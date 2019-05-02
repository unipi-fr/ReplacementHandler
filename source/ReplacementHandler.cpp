#include "ReplacementHandler.h"
#include <math.h>
#include <limits.h>
#include <cstring>
#include <cstdint>
#include <iostream>

#include <time.h>

using namespace std;



class PLRUReplacementHandler : public IReplacementPolicy {
private:
    uint16_t* _dataStructure;
    size_t _sizeDataStructure;
    uint8_t _nWayAssociative;
    uint8_t _numberOfOffsetBits;
    uint16_t _addressMaskOfIndex;
    
	uint16_t extractIndex(uint16_t address){
        uint16_t index = address & _addressMaskOfIndex;
        index = index >> _numberOfOffsetBits;
        return index;
    }
    
    void createMask(uint8_t numberOfIndexBits, uint8_t numberOfOffsetBits){
        _numberOfOffsetBits = numberOfOffsetBits;
        _addressMaskOfIndex = 0;// inizializza con tutti 0
		for(int i = 0;i<numberOfIndexBits;++i){
			_addressMaskOfIndex <<= 1;
			++_addressMaskOfIndex;
		}
		_addressMaskOfIndex <<= _numberOfOffsetBits;     
    }
public:
    PLRUReplacementHandler(uint8_t numberOfIndexBits, uint8_t numberOfOffsetBits, uint8_t nWayAssociative){
		if(nWayAssociative>16){
			throw nWayException();
		}
        if(numberOfIndexBits > UCHAR_MAX - numberOfOffsetBits){
            //TODO: gestire errore overflow della somma 
            return;
        }
        if (numberOfAddressBits <= numberOfIndexBits + numberOfOffsetBits) {
            //TODO: gestire errore "il numero dei bit offset+index supera i bit dell'indirizzo"
            //Se  numberOfAdressBits = alpha + beta + gamma --> ne consegue che questo if è sempre verificato dato che 
            //la somma di due qualsiasi delle componenti sarà sempre minore della somma di tutte e tre
            return;
        }
    
        createMask(numberOfIndexBits, numberOfOffsetBits);
        _nWayAssociative = nWayAssociative;
        _sizeDataStructure = pow(2, numberOfIndexBits);
        _dataStructure = new uint16_t[_sizeDataStructure];
    }

    uint8_t findVictim(uint16_t address){
        uint16_t index = extractIndex(address);
       
        uint16_t counter = ~(_dataStructure[index]);
        
        uint8_t cc = 0;
        int i = 0;
        
        for(uint8_t n = _nWayAssociative/2; n > 0; n /= 2){
            uint16_t bit = counter & (1u << i);
            
            if(bit > 0) {
                cc += n;
                i += n;    
            } else {
                i += 1;
            }                
        }
        
        return cc;
    }  

    void updateStatistics(uint16_t address, uint8_t cacheColumn){
        //TODO: Insert code here
        
        uint16_t index = extractIndex(address);
		uint16_t counter = _dataStructure[index];
        
        int i = 0;
        uint8_t cc = cacheColumn;
        
        for(uint8_t n = _nWayAssociative/2; n > 0; n /= 2){
            
            if(cc >= n) 
            {
                //E' un 1
                counter |= (1u << i); // Setto il bit corrispondente
                i += n;
                cc -= n;
            } else {
                //E' uno 0
                counter &= ~(1u << i); // Azzero il bit corrispondente
                i += 1;
            }
               
        }
		_dataStructure[index] = counter;
    }

    void invalidateStatistics(uint16_t address, uint8_t cacheColumn){}
};

class LFUReplacementHandler : public IReplacementPolicy {
private:
	uint8_t 	*ass_m;				//Matrice associata, struttura dati contatore
	uint8_t  	index_size;	
	uint8_t  	offset_size;
	uint8_t  	n_ways;				// numero di vie della cache associativa
	uint8_t   	n_rows;				// numero degli indici
	uint16_t	last_incremented;	// ultimo elemento incrementato. usato per evitare incrementi sequenziali continuativi

	/*Parametri di DEBUG*/
	enum debug_par{	ASSOCIATIVE_MATRIX, 
					INDEX, 
					VICTIM
				};

	/*Funzionalità per DEBUG*/
	void print_debug(enum debug_par parameter){
		switch(parameter){
			case ASSOCIATIVE_MATRIX:
				for(uint8_t i = 0; i < n_rows; i++){
					
					for(uint8_t j = 0; j < n_ways; j++)
						printf("%u \t",ass_m[i * n_ways + j]);
					
					cout << endl;
				}
			break;

			case INDEX:
				//TODO se si vuole aggiungere
			break;

			case VICTIM:
				//TODO se si vuole aggiungere
			break;
		}
	}


public:

    LFUReplacementHandler(uint8_t numberOfIndexBits, uint8_t numberOfOffsetBits, uint8_t nWayAssociative){

    	/*Inizializzazione dei parametri della classe*/
		n_rows      	 = pow(2, numberOfIndexBits);
		n_ways      	 = nWayAssociative;
		index_size  	 = numberOfIndexBits;
		offset_size 	 = numberOfOffsetBits;
		last_incremented = -1;

		ass_m = new uint8_t[n_ways * n_rows];			//creazione dinamica matrice associativa [rows][numero di vie]
    	memset(ass_m, '0', n_rows * nWayAssociative); 	//mette a 0 tutte le celle della matrice associativa
		
		 //INIZIALIZZAZIONE RANDOMICA
    	srand(time(NULL));
		for(uint8_t i = 0; i < n_rows; i++){
			for (uint8_t j = 0; j < n_ways; j++)
			{
				ass_m[i * n_ways + j] = (rand() % 255 + 1);
			}		
		}
	}

	/* Qua facciamo in modo che passato un indirizzo si analizza l' indice derivato dall' indirizzo *
	 * stesso e si restituisce il valore corrispondente alla colonna nella matrice associativa che  *
	 * corrisponde alla via dal quale il valore vittima deve essere rimosso 						*/
	uint8_t findVictim(uint16_t address){
		
		uint8_t 	vict 	= 0;								//inizializzata a 0 perchè è il valore minimo della via da scegliere
		uint8_t 	min_cnt = 255;								//si sceglie 2^8 perchè valore più grande a 8 bit non si può avere
		uint16_t 	mask 	= pow(2, index_size) - 1;			//maschera per l'operazione di shift destro 
		uint8_t 	index 	= (address >> offset_size) & mask;	//derivo il valore corretto dalla combinazione algebrica del registro a 16bit		

		/* Controllo la matrice e seleziono la vittima di riga 'index' e colonna 'i' */
		for(uint8_t i = 0; i < n_ways; i++){
			if(ass_m[index * n_ways + i] < min_cnt){
				 min_cnt = ass_m[index * n_ways + i];
				 vict = i;
		    }
		}

		print_debug(ASSOCIATIVE_MATRIX);											//funzione per stampa di debug

		return vict;
	}

	void updateStatistics(uint16_t address, uint8_t cacheColumn){
		
		uint16_t 	mask 	= pow(2, index_size) - 1;			//maschera per l'operazione di shift destro 
		uint8_t 	index 	= (address >> offset_size) & mask;	//derivo il valore corretto dalla combinazione algebrica del registro a 16bit		

		/*if(newData)												//newData distingue se è un nuovo dato in cache
			ass_m[index * n_ways + cacheColumn] = 1;			//Setting del contatore a 1, primo accesso
		
		else*/
		

		if(ass_m[index * n_ways + cacheColumn] < 255 && ((index * n_ways + cacheColumn) != last_incremented)) {
			ass_m[index * n_ways + cacheColumn]++;				//incremento del contatore
			last_incremented = index * n_ways + cacheColumn;
		}

		print_debug(ASSOCIATIVE_MATRIX);
	}

	void invalidateStatistics(uint16_t address, uint8_t cacheColumn){
		uint16_t 	mask 	= pow(2, index_size) - 1;			//maschera per l'operazione di shift destro 
		uint8_t 	index 	= (address >> offset_size) & mask;	//derivo il valore corretto dalla combinazione algebrica del registro a 16bit		

		ass_m[index * n_ways + cacheColumn] = 0;				//resetta il contatore della pagina
	}
};


class RNDReplacementHandler : public IReplacementPolicy {
private:
	uint8_t  	n_ways;
public:
    RNDReplacementHandler(uint8_t numberOfIndexBits, uint8_t numberOfOffsetBits, uint8_t nWayAssociative){
		n_ways = nWayAssociative;			// Inizializza la variabile privata con il numero delle vie
		srand(time(NULL));					// Inizializza il seed per la funzione rand()
	}

	uint8_t findVictim(unsigned short address){
		return rand() % n_ways;					//ritorna un valore randomico tra 0 e n_ways-1
	}

	void updateStatistics(unsigned short address, uint8_t cacheColumn){
	}

	void invalidateStatistics(uint16_t address, uint8_t cacheColumn){
	}
};


ReplacementHandler::ReplacementHandler(uint8_t numberOfIndexBits, uint8_t numberOfOffsetBits, uint8_t nWayAssociative, PoliciesOffered policy) {
	_policy = policy;

	switch (policy){
		case PLRU:
			_policyAdopted = new PLRUReplacementHandler(numberOfIndexBits,numberOfOffsetBits,nWayAssociative);
			break;
		case LFU:
			_policyAdopted = new LFUReplacementHandler(numberOfIndexBits,numberOfOffsetBits,nWayAssociative);
			break;
		case RND:
			_policyAdopted = new RNDReplacementHandler(numberOfIndexBits,numberOfOffsetBits,nWayAssociative);
			break;
		default:
			//TODO: gestire l'errore
			break;
	}
	
}

/*Returns the cacheColumn where the victim was chosen*/
unsigned char ReplacementHandler::findVictim(uint16_t address) {
	return _policyAdopted->findVictim(address);
}

void ReplacementHandler::updateStatistics(uint16_t address, uint8_t cacheColumn){
	_policyAdopted->updateStatistics(address,cacheColumn);
}

void ReplacementHandler::invalidateStatistics(uint16_t address, uint8_t cacheColumn){
	_policyAdopted->invalidateStatistics(address,cacheColumn);
}
