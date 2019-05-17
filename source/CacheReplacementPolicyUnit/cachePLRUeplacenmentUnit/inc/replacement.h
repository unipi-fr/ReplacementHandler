#ifndef REPLACEMENT_H
#define REPLACEMENT_H
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>



//DEFINIZIONI DA SPECIFICA

#define ADDRESS_LEN               16  	//Lunghezza dell'indirizzo che ci viene passato fissato a 16 bit 
#define ADDRESS_OFFSET            3  	//definisco un parametro di offset per i test (è solo un esempio e può variare al momento della creazione effettiva dell'oggetto)
#define ADDRESS_INDEX_SIZE        6  	//definisco un parametro di indice per i test (è solo un esempio e può variare al momento della creazione effettiva dell'oggetto)
#define NWAYS_ASSOCIATIVE         8  	//Numero di vie della cache associativa
#define DATASTRUCTURE_SIZE        64    // 2^ADDRESS_INDEX_SIZE = 2^6
#define NUMBER_OF_ADDRESSES_TESTED 64
#define NUMBER_OF_MAKS_TESTED     15

//PROTOTIPI

void initPLRU(uint32_t* dataStructure, size_t sizeDataStructure,uint8_t nWayAssociative, uint8_t numberOfOffsetBits, uint16_t addressMaskOfIndex);
uint16_t createMask(uint8_t numberOfIndexBits, uint8_t numberOfOffsetBits);
uint16_t extractIndex(uint16_t address);
uint8_t findVictim(uint16_t address);//funzione che permette di selezionare la vittima con criterio LRU
uint32_t updateStatistics(uint16_t address, uint8_t cacheColumn);
//void updateStatistics(uint16_t address, uint8_t cacheColumn, uint8_t *ass_m);
//void invalidateStatistics(uint16_t address, uint8_t cacheColumn, uint8_t *ass_m);

#endif
