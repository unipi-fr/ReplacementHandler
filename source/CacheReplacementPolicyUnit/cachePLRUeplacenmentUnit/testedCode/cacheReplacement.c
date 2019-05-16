#include "replacement.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

uint32_t* _dataStructure;
size_t _sizeDataStructure;
uint8_t _nWayAssociative;
uint8_t _numberOfOffsetBits;
uint16_t _addressMaskOfIndex;

void initPLRU(uint32_t* dataStructure, size_t sizeDataStructure,uint8_t nWayAssociative, uint8_t numberOfOffsetBits, uint16_t addressMaskOfIndex){
    _dataStructure = dataStructure;
    _sizeDataStructure = sizeDataStructure;
    _nWayAssociative = nWayAssociative;
    _numberOfOffsetBits = numberOfOffsetBits;
    _addressMaskOfIndex = addressMaskOfIndex;
}

uint16_t extractIndex(uint16_t address){
    uint16_t index = address & _addressMaskOfIndex;
    index = index >> _numberOfOffsetBits;
    return index;
}

uint16_t createMask(uint8_t numberOfIndexBits, uint8_t numberOfOffsetBits){
    _numberOfOffsetBits = numberOfOffsetBits;
    uint16_t addressMaskOfIndex = 0;// inizializza con tutti 0
    
    for(int i = 0;i<numberOfIndexBits;++i){
        addressMaskOfIndex <<= 1;
        ++addressMaskOfIndex;
    }

    addressMaskOfIndex <<= _numberOfOffsetBits; 
    return addressMaskOfIndex;    
}

uint8_t findVictim(uint16_t address){
    
}

void updateStatistics(uint16_t address, uint8_t cacheColumn, uint8_t *ass_m){
    
}

void invalidateStatistics(uint16_t address, uint8_t cacheColumn, uint8_t *ass_m){
	
};

