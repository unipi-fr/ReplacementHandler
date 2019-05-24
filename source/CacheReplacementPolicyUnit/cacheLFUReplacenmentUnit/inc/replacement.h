#ifndef REPLACEMENT_H
#define REPLACEMENT_H
#include <stdbool.h>
#include <stdint.h>



//DEFINIZIONI DA SPECIFICA

#define ADDRESS_LEN               16  	// Fixed length bits of the address 
#define COUNTER_SIZE              8  	// Every counter of the associated matrix to the cache it's on 8 bits 
#define ADDRESS_OFFSET            3  	// Defining an offset parameter for testing (it is just an example and may vary)
#define ADDRESS_INDEX_SIZE        3  	// Defining an offset parameter for testing (it is just an example and may vary)
#define NWAYS_ASSOCIATIVE         8  	// Number of the ways of the set associative cache

#define MIN_RAND				  1	    // Min value of the random generation
#define MAX_RAND			 	  127	// Random value to add in order to misrepresent the expected value of the function findvictim 
#define IDX_1 				 	  3		// Index to the data to misrepresent 
#define IDX_2				      7     // Index to the data to misrepresent 
#define IDX_3				      0     // Index to the data to misrepresent 

#define INVALIDATE_UB			  15	// Number of indexes to invalidate in the function invalidateStatistics()
#define MAX_CACHE_ELEMENTS        64    // Max number of the cache elements
#define MAX_RANDOM_TEST			  1024 

//PROTOTIPI

uint8_t check_adress_index(uint16_t address);  		  //testing the behaviour of the mechanism to find the index starting from the address
uint8_t findVictim(uint16_t address, uint8_t *ass_m); //finding the victim according to LFU policy


void updateStatistics(uint16_t address, uint8_t cacheColumn, uint8_t *ass_m);
void invalidateStatistics(uint16_t address, uint8_t cacheColumn, uint8_t *ass_m);

uint8_t randomPolicy(void);


#endif
