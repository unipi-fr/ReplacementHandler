#ifndef REPLACEMENT_H
#define REPLACEMENT_H
#include <stdbool.h>
#include <stdint.h>



//DEFINIZIONI DA SPECIFICA

#define ADDRESS_LEN         16  //Lunghezza dell'indirizzo che ci viene passato fissato a 16 bit 
#define COUNTER_SIZE         8  //Ogni contatore nella matrice è a 8 bit 
#define ADDRESS_OFFSET       3  //definisco un parametro di offset per i test (è solo un esempio e può variare al momento della creazione effettiva dell'oggetto)
#define ADDRESS_INDEX_SIZE   3  //definisco un parametro di indice per i test (è solo un esempio e può variare al momento della creazione effettiva dell'oggetto)
#define NWAYS_ASSOCIATIVE    8  //Numero di vie della cache associativa





//PROTOTIPI

uint8_t check_adress_index(uint16_t address);  //funzione che testa il corretto comportamento del meccanismo per trovare l'indice dall'indirizzo 
uint8_t findVictim(uint16_t address, uint8_t *ass_m); //funzione che permette di selezionare la vittima con criterio LFU


#endif
