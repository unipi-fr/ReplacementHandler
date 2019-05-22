#include "replacement.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

uint32_t _dataStructure[DATASTRUCTURE_SIZE];
size_t _sizeDataStructure;
uint8_t _nWayAssociative;
uint8_t _numberOfOffsetBits;
uint16_t _addressMaskOfIndex;

/*Just for testing*/
void initPLRU(uint32_t* dataStructure, size_t sizeDataStructure,uint8_t nWayAssociative, uint8_t numberOfOffsetBits, uint16_t addressMaskOfIndex){
    for (size_t i = 0; i < sizeDataStructure; i++)
    {
        _dataStructure[i] = dataStructure[i];
    }
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
    uint16_t index = extractIndex(address);
       
        uint32_t counter = ~(_dataStructure[index]);
        
        uint8_t cacheColum = 0;
        int i = 0;
        
        for(uint8_t n = _nWayAssociative/2; n > 0; n /= 2){
            uint32_t bit = counter & (1u << i);
            
            if(bit > 0) {
                cacheColum += n;
                i += n;    
            } else {
                i += 1;
            }                
        }
        
        return cacheColum;
}

uint32_t updateStatistics(uint16_t address, uint8_t cacheColumn){
    uint16_t index = extractIndex(address);
    uint32_t counter = _dataStructure[index];
    
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
    return _dataStructure[index];
}

void invalidateStatistics(uint16_t address, uint8_t cacheColumn){
	
};