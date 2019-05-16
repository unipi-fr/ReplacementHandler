#ifndef REPLACEMENT_H
#define REPLACEMENT_H
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>



//DEFINIZIONI DA SPECIFICA

#define ADDRESS_LEN               16  	//Lunghezza dell'indirizzo che ci viene passato fissato a 16 bit 
#define COUNTER_SIZE              8  	//Ogni contatore nella matrice è a 8 bit 
#define ADDRESS_OFFSET            3  	//definisco un parametro di offset per i test (è solo un esempio e può variare al momento della creazione effettiva dell'oggetto)
#define ADDRESS_INDEX_SIZE        3  	//definisco un parametro di indice per i test (è solo un esempio e può variare al momento della creazione effettiva dell'oggetto)
#define NWAYS_ASSOCIATIVE         8  	//Numero di vie della cache associativa

#define MIN_RAND				  1	    //valore minimo della generazione casuale
#define MAX_RAND			 	  127	//valore casuale da aggiungere per falsare il valore aspettato dalla find victim 
#define IDX_1 				 	  3		//indice del dato da falsare nel valore aspettato 
#define IDX_2				      7     //indice del dato da falsare nel valore aspettato 
#define IDX_3				      0     //indice del dato da falsare nel valore aspettato 

#define INVALIDATE_UB			  15	//numero di indirizzi da invalidare in invalidateStatistics()
#define MAX_CACHE_ELEMENTS        64    //2^16 dato che gli indirizzi sono a 16 bit
#define MAX_RANDOM_TEST			  1024 

//PROTOTIPI

void initPLRU(uint32_t* dataStructure, size_t sizeDataStructure,uint8_t nWayAssociative, uint8_t numberOfOffsetBits, uint16_t addressMaskOfIndex);
uint16_t createMask(uint8_t numberOfIndexBits, uint8_t numberOfOffsetBits);
//uint8_t findVictim(uint16_t address, uint8_t *ass_m); //funzione che permette di selezionare la vittima con criterio LFU


//void updateStatistics(uint16_t address, uint8_t cacheColumn, uint8_t *ass_m);
//void invalidateStatistics(uint16_t address, uint8_t cacheColumn, uint8_t *ass_m);



#endif
