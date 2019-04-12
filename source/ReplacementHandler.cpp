#include "ReplacementHandler.h"
#include <math.h>
#include <limits.h>
#include <cstring>
#include <cstdint>
#include <iostream>
using namespace std;




















class PLRUReplacementHandler : public IReplacementPolicy {
private:
	unsigned char* _dataStructure;
	size_t _sizeDataStructure;
public:
    PLRUReplacementHandler(uint8_t numberOfIndexBits, uint8_t numberOfOffsetBits, uint8_t nWayAssociative){
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
	_sizeDataStructure = pow(2, numberOfIndexBits);
	_dataStructure = new unsigned char[_sizeDataStructure];
	}

	uint8_t findVictim(unsigned short address){
		//TODO: Insert Code here
		return 0;
	}

	void notifyOperation(unsigned short address, uint8_t cacheColumn){
		//TODO: Insert code here
	}
};

class LFUReplacementHandler : public IReplacementPolicy {
private:
	uint8_t 	*ass_m;
	uint8_t  	index_size;
	uint8_t  	offset_size;
	uint8_t  	n_ways;
	uint8_t   	n_rows;

	enum debug_par{ ASSOCIATIVE_MATRIX,
				    INDEX,
		            VICTIM
		                   };



	void print_debug(enum debug_par parameter){
		switch(parameter){
			case ASSOCIATIVE_MATRIX:
				for(uint8_t i = 0; i < n_rows; i++){
					for(uint8_t j = 0; j < n_ways; j++){
						cout << ass_m[i * n_ways + j] << '\t';
					}
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

		n_rows      = pow(2, numberOfIndexBits);
		n_ways      = nWayAssociative;
		index_size  = numberOfIndexBits;
		offset_size = numberOfOffsetBits;


		ass_m = new uint8_t[n_ways * n_rows];			//matrice associativa [rows][numero di vie]
    	memset(ass_m, '0', n_rows * nWayAssociative);   //mette a 0 tutte le celle della matrice associativa

	}

	/* Qua facciamo in modo che passato un indirizzo si analizza l' indice derivato dall' indirizzo *
	 * stesso e si restituisce il valore corrispondente alla colonna nella matrice associativa che  *
	 * corrisponde alla via dal quale il valore vittima deve essere rimosso 						*/
	uint8_t findVictim(uint16_t address){
		
		uint8_t 	vict 	= 0;								//inizializzata a 0 perchè è il valore minimo della via da scegliere
		uint8_t 	min_cnt = 255;								//si sceglie 2^8 perchè valore più grande a 8 bit non si può avere
		uint16_t 	mask 	= pow(2, index_size) - 1;			//maschera per l'operazione di shift destro 
		uint8_t 	index 	= (address >> offset_size) && mask;	//derivo il valore corretto dalla combinazione algebrica del registro a 16bit		

		/* Controllo la matrice e seleziono la vittima in base al valore del contatore */
		for(uint8_t i = 0; i < n_ways; i++){
			if(ass_m[index * n_ways + i] < min_cnt){
				 min_cnt = ass_m[index * n_ways + i];
				 vict = i;
		    }
		}

		print_debug();											//funzione per stampa di debug

		return vict;
	}

	void notifyOperation(uint16_t address, uint8_t cacheColumn){
		//TODO: Insert code here
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
		default:
			//TODO: gestire l'errore
			break;
	}
	
}

/*Returns the cacheColumn where the victim was chosen*/
unsigned char ReplacementHandler::findVictim(uint16_t address) {
	return _policyAdopted->findVictim(address);
}

void ReplacementHandler::notifyOperation(uint16_t address, uint8_t cacheColumn){
	_policyAdopted->notifyOperation(address,cacheColumn);
}


