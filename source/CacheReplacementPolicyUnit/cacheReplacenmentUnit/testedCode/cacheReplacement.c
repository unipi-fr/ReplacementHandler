



#include "replacement.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>



/* In ogni funzione dobbiamo aggiungere un controllo sulla soglia minima se sono in motorIncrement e un controllo sulla soglia massima se sono in motorDecrement,
Stessa cosa bisognerebbe fare in code.c all̈́' inizio di ogni case */




uint8_t check_adress_index(uint16_t address){
	
	uint16_t mask = pow(2, ADDRESS_INDEX_SIZE) - 1;

	return  (address >> ADDRESS_OFFSET) & mask;
}





uint8_t findVictim(uint16_t address, uint8_t *ass_m){
    
    uint8_t   vict    = 0;                					 //inizializzata a 0 perchè è il valore minimo della via da scegliere
    uint8_t   min_cnt = 255;                				 //si sceglie 2^8 perchè valore più grande a 8 bit non si può avere
    uint16_t   mask   = pow(2, ADDRESS_INDEX_SIZE) - 1;      //maschera per l'operazione di shift destro 
    uint8_t   index   = (address >> ADDRESS_OFFSET) & mask;  //derivo il valore corretto dalla combinazione algebrica del registro a 16bit    

    /* Controllo la matrice e seleziono la vittima di riga 'index' e colonna 'i' */
    for(uint8_t i = 0; i < NWAYS_ASSOCIATIVE; i++){
      if(ass_m[index * NWAYS_ASSOCIATIVE + i] < min_cnt){
         min_cnt = ass_m[index * NWAYS_ASSOCIATIVE + i];
         vict = i;
        }
    }

    return vict;
  }





void updateStatistics(uint16_t address, uint8_t cacheColumn, uint8_t *ass_m){

	uint16_t 	mask 	= pow(2, ADDRESS_INDEX_SIZE) - 1;			//maschera per l'operazione di shift destro 
	uint8_t 	index 	= (address >> ADDRESS_OFFSET) & mask;	    //derivo il valore corretto dalla combinazione algebrica del registro a 16bit		

	if(ass_m[index * NWAYS_ASSOCIATIVE + cacheColumn] < 255) {
		ass_m[index * NWAYS_ASSOCIATIVE + cacheColumn]++;			//incremento del contatore
	}

}




void invalidateStatistics(uint16_t address, uint8_t cacheColumn, uint8_t *ass_m){
	
	uint16_t 	mask 	= pow(2, ADDRESS_INDEX_SIZE) - 1;			//maschera per l'operazione di shift destro 
	uint8_t 	index 	= (address >> ADDRESS_OFFSET) & mask;	//derivo il valore corretto dalla combinazione algebrica del registro a 16bit		

	ass_m[index * NWAYS_ASSOCIATIVE + cacheColumn] = 0;				//resetta il contatore della pagina
};




uint8_t randomPolicy(void){
	return rand()%(MAX_CACHE_ELEMENTS - 1);
}