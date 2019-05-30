/*ReplacementHandler.cpp	
details:		ReplacementHandler contains the implementation of replacement policies

authors:		Edoardo Cittadini, Davide Rasla, Gerlando Sciangula, Francesco Ronchieri, Alessandro Madonna

date:			15-05-2019
*/	

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
    uint32_t* _dataStructure;
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
		if(nWayAssociative>32){
			throw NWayException();
		}
        if(numberOfIndexBits > UCHAR_MAX - numberOfOffsetBits){
			//Overflow of sum
            throw InvalidParametersException();
            return;
        }
        if (numberOfAddressBits <= numberOfIndexBits + numberOfOffsetBits) {
            //Handling error: the number of bits of offest+index exceed the bits of entire adress
			throw InvalidParametersException();
        }
    
        createMask(numberOfIndexBits, numberOfOffsetBits);
        _nWayAssociative = nWayAssociative;
        _sizeDataStructure = pow(2, numberOfIndexBits);
        _dataStructure = new uint32_t[_sizeDataStructure];
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

    void updateStatistics(uint16_t address, uint8_t cacheColumn){
        uint16_t index = extractIndex(address);
		uint32_t counter = _dataStructure[index];
        
        int i = 0;
        uint8_t cc = cacheColumn;
        //cycling the counters bits
        for(uint8_t n = _nWayAssociative/2; n > 0; n /= 2){
            //check where the cache it's related to the first or second half
            if(cc >= n) 
            {
                //if second half
                counter |= (1u << i); // set to 1 the corresponding bit of the counter related that half
                i += n;	// set i pointing next bit to be checked (corresponding the bit of the second half)
                cc -= n; //update cache column for the next iteration
            } else {
                //if second half
                counter &= ~(1u << i); // set to 1 the corresponding bit of the counter related that half
                i += 1; // set i pointing next bit to be checked (corresponding the bit of the second half)
                // cache column it's arledy updated for the next iteration
            }
               
        }
		//updating corresponding counter
		_dataStructure[index] = counter;
    }

    void invalidateStatistics(uint16_t address, uint8_t cacheColumn){}
};

class LFUReplacementHandler : public IReplacementPolicy {
private:
	uint8_t 	*ass_m;				//Associated matrix
	uint8_t  	index_size;	
	uint8_t  	offset_size;
	uint8_t  	n_ways;				// number of way of associative cache 
	uint8_t   	n_rows;				// number of indices of cache
	uint16_t	last_incremented;	// last incremented item. Used in order to avoid consecutive increments on the same item

public:

    LFUReplacementHandler(uint8_t numberOfIndexBits, uint8_t numberOfOffsetBits, uint8_t nWayAssociative){

    	/*Initialization of class parameters*/
		n_rows      	 = pow(2, numberOfIndexBits);
		n_ways      	 = nWayAssociative;
		index_size  	 = numberOfIndexBits;
		offset_size 	 = numberOfOffsetBits;
		last_incremented = -1;

		ass_m = new uint8_t[n_ways * n_rows];			// dynamic creation of associative matrix [rows] [number of ways]
    	memset(ass_m, '0', n_rows * nWayAssociative); 	// set all the cells of the associative matrix to 0
		
		/* Randomic Initialization

		for(uint8_t i = 0; i < n_rows; i++){
			for (uint8_t j = 0; j < n_ways; j++)
			{
				ass_m[i * n_ways + j] = (rand() % 255 + 1);
			}		
		}*/
	}

/* Local functions */

/* This function make sure that after having passed an address the index, derived from the address
itself, is analyzed and returns the value corresponding to the column in the associative matrix which 
 corresponds to the way from which the victim value must be removed.
*/

	uint8_t findVictim(uint16_t address){
		
		uint8_t 	vict 	= 0;								//initialized to 0 because it is the minimum value of the way to choose
		uint8_t 	min_cnt = 255;								//we choose 2^8 - 1 because bigger 8-bit value can't be had
		uint16_t 	mask 	= pow(2, index_size) - 1;			//mask for the right shift operation
		uint8_t 	index 	= (address >> offset_size) & mask;	//get the correct value from the algebraic combination of the 16bit register	

/* Control the matrix and select the victim of row 'index' and column 'i' */
		for(uint8_t i = 0; i < n_ways; i++){
			if(ass_m[index * n_ways + i] < min_cnt){
				 min_cnt = ass_m[index * n_ways + i];
				 vict = i;
		    }
		}
										

		return vict;
	}

/* Local functions */

/* \details This function after after calculating the index through the mask, it accesses
 the block and increments the counter, as long as it has not already increased it immediately before
*/
	void updateStatistics(uint16_t address, uint8_t cacheColumn){
		
		uint16_t 	mask 	= pow(2, index_size) - 1;			//mask for the right shift operation
		uint8_t 	index 	= (address >> offset_size) & mask;	//get the correct value from the algebraic combination of the 16bit register	

		if(ass_m[index * n_ways + cacheColumn] < 255 && ((index * n_ways + cacheColumn) != last_incremented)) {
			ass_m[index * n_ways + cacheColumn]++;				//increment of the counter 
			last_incremented = index * n_ways + cacheColumn;
		}

	}

/* Local functions */

/* \details This function after after calculating the index through the mask, it accesses
 the block set the counter to zero
*/
	void invalidateStatistics(uint16_t address, uint8_t cacheColumn){
		uint16_t 	mask 	= pow(2, index_size) - 1;			//mask for the right shift operation
		uint8_t 	index 	= (address >> offset_size) & mask;	//get the correct value from the algebraic combination of the 16bit register			

		ass_m[index * n_ways + cacheColumn] = 0;				//reset the counter
	}
};


class RNDReplacementHandler : public IReplacementPolicy {
private:
	uint8_t  	n_ways;
public:
    RNDReplacementHandler(uint8_t numberOfIndexBits, uint8_t numberOfOffsetBits, uint8_t nWayAssociative){
		n_ways = nWayAssociative;			//Initialize the private variable with the number of ways
		srand(time(NULL));					//Initialize the seed for rand()
	}
/* Local functions */

/* \details This function returns the value corresponding to the column in the associative matrix which 
 corresponds to the way from which the victim value must be removed.
*/
	uint8_t findVictim(unsigned short address){
		return rand() % n_ways;					//returns a random value between 0 and n_ways -1 
	}

	void updateStatistics(unsigned short address, uint8_t cacheColumn){
	}

	void invalidateStatistics(uint16_t address, uint8_t cacheColumn){
	}
};


ReplacementHandler::ReplacementHandler(uint8_t numberOfIndexBits, uint8_t numberOfOffsetBits, uint8_t nWayAssociative, PoliciesOffered policy) {
	_policy = policy;

	switch (policy){
		case PLRU_RH:
			_policyAdopted = new PLRUReplacementHandler(numberOfIndexBits,numberOfOffsetBits,nWayAssociative);
			break;
		case LFU_RH:
			_policyAdopted = new LFUReplacementHandler(numberOfIndexBits,numberOfOffsetBits,nWayAssociative);
			break;
		case RND_RH:
			_policyAdopted = new RNDReplacementHandler(numberOfIndexBits,numberOfOffsetBits,nWayAssociative);
			break;
		default:
			throw PolicyNotValidException();
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
