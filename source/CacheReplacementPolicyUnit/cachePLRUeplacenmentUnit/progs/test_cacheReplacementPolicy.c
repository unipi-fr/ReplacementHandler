#include <stdio.h>  
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
//#include </home/edoardo/Scrivania/CacheReplacementPolicyUnit/cachePLRUReplacenmentUnit/CUnit-2.1-0/CUnit/Headers/Basic.h>
//#include </home/edoardo/Scrivania/CacheReplacementPolicyUnit/cachePLRUReplacenmentUnit/CUnit-2.1-0/CUnit/Headers/Automated.h>
#include </home/fraronk/repositories/replacementHandler/source/CacheReplacementPolicyUnit/cachePLRUeplacenmentUnit/CUnit-2.1-0/CUnit/Headers/Basic.h>
#include </home/fraronk/repositories/replacementHandler/source/CacheReplacementPolicyUnit/cachePLRUeplacenmentUnit/CUnit-2.1-0/CUnit/Headers/Automated.h>
#include "replacement.h"

uint8_t createMask_numberOfOffsetBits[NUMBER_OF_MAKS_TESTED] = 
{
  3, 3, 3,  4, 4, 4,
  5, 5, 5,  6, 6, 6,
  7, 7, 7
};

uint8_t createMask_numberOfIndexBits[NUMBER_OF_MAKS_TESTED] =
{
  3, 5, 8,  3, 5, 8,
  3, 5, 8,  3, 5, 8,
  3, 5, 8
};

uint16_t createMask_expectedMasks[NUMBER_OF_MAKS_TESTED] = 
{
   56,  248,  2040,   112,  496,  4080,
  224,  992,  8160,   448, 1984, 16320,
  896, 3968, 32640
};

uint16_t extractIndex_expectedIndex[NUMBER_OF_ADDRESSES_TESTED] = 
{ 
  12, 9, 27, 31, 7, 24, 0, 14, 13, 9, 16, 28, 12, 7, 11, 10, 2, 27, 4, 3, 6, 5, 4, 28, 10, 18, 15, 30, 7, 27, 7, 19, 
  5, 2, 19, 12, 27, 19, 27, 9, 28, 11, 5, 9, 19, 17, 20, 21, 13, 24, 25, 19, 30, 29, 16, 8, 15, 0, 7, 22, 28, 14, 10, 15
};

/*
  consideriamo l'indice a 6 bit => 2^6 = 64 elementi
  cache a 8 vie => 7 bit per il contatore 
*/
uint8_t findVictim_expectedVictim[DATASTRUCTURE_SIZE] = 
{ 
  7, 3, 7, 1, 7, 3, 7, 0,
  7, 2, 7, 1, 7, 2, 7, 0,
  5, 3, 5, 1, 5, 3, 5, 0,
  5, 2, 5, 1, 5, 2, 5, 0,
  7, 3, 7, 1, 7, 3, 7, 0,
  7, 2, 7, 1, 7, 2, 7, 0,
  4, 3, 4, 1, 4, 3, 4, 0,
  4, 2, 4, 1, 4, 2, 4, 0
 };

uint32_t dataStructure[DATASTRUCTURE_SIZE] = 
{
  0     ,1      ,2      ,3      ,4     ,5      ,6      ,7 ,
  8     ,9      ,10     ,11     ,12    ,13     ,14     ,15,
  16    ,17     ,18     ,19     ,20    ,21     ,22     ,23,
  24    ,25     ,26     ,27     ,28    ,29     ,30     ,31,
  32    ,33     ,34     ,35     ,36    ,37     ,38     ,39,
  40    ,41     ,42     ,43     ,44    ,45     ,46     ,47,
  48    ,49     ,50     ,51     ,52    ,53     ,54     ,55,
  56    ,57     ,58     ,59     ,60    ,61     ,62     ,63,
};

uint16_t address_hex[NUMBER_OF_ADDRESSES_TESTED] = 
{  
  0x7164, 0x1c4e, 0x30da, 0xdfd, 0x6738, 0x1c3, 0x4601, 0x3875, 0xee6e, 0x3d4b, 0x2281, 0x13e1, 
  0xbd65, 0x323d, 0xef5e, 0x1f55, 0xe810, 0x84df, 0x5221, 0xb31f, 0x1d32, 0x572e, 0x2e21, 0x3ae7, 
  0xa153, 0x6194, 0xc87e, 0x6af6, 0xce38, 0x77de, 0x4d3c, 0xbf9d, 0x142c, 0x7e17, 0xcd9a, 0x7b64, 
  0xffd9, 0x939b, 0xb3d9, 0xee49, 0x50e6, 0x565a, 0x822a, 0x8e4c, 0x8898, 0xf188, 0xada1, 0xf0a8, 
  0x7669, 0xffc2, 0xa3c8, 0x139b, 0x56f1, 0x51e9, 0xce82, 0x7844, 0xb37d, 0x9701, 0x633b, 0x1b7, 
  0xee0, 0xb077, 0xc154, 0xc87e
};



uint16_t address_dec[NUMBER_OF_ADDRESSES_TESTED] = 
{ 
  29028, 7246, 12506, 3581, 26424, 451, 17921, 14453, 61038, 15691, 8833, 5089, 
  48485, 12861, 61278, 8021, 59408, 34015, 21025, 45855, 7474, 22318, 11809, 15079, 
  41299, 24980, 51326, 27382, 52792, 30686, 19772, 49053, 5164, 32279, 52634, 31588, 
  65497, 37787, 46041, 61001, 20710, 22106, 33322, 36428, 34968, 61832, 44449, 61608, 
  30313, 65474, 41928, 5019, 22257, 20969, 52866, 30788, 45949, 38657, 25403, 439, 
  3808, 45175, 49492, 51326
};

uint32_t mask_counter_8wayAssociative[]  = {
  0b111 , 0b111 , 0b1011 , 0b1011 , 0b110001 , 0b110001 , 0b1010001 , 0b1010001
};

uint32_t counterValue_8wayAssociative[] = { 
  0 ,  4 ,  2 ,  10 ,  1 ,  33 ,  17 ,  81
};

/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite1(void)
{

  printf ("\nInitializing PLRUSuite\n");
  return 0;
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void)
{
  printf ("\nCompleting PLRUSuite\n");
  return 0;
}

void test_createMask(void) {
  for(int i = 0;i < NUMBER_OF_MAKS_TESTED; i++){
    CU_ASSERT_EQUAL(createMask(createMask_numberOfIndexBits[i], createMask_numberOfOffsetBits[i]),createMask_expectedMasks[i]);
  }
}

void test_extractIndex(void) {
  for(int i = 0;i < NUMBER_OF_ADDRESSES_TESTED; i++){
    /*
      data_structure = null because it isnt needed
      size_datatstructure = 0 because it isnt needed
      nWayAssociative = 0 because it isnt needed
      numberOfOffsetBits = 3 specific value for the test 
      addressMaskOfIndex = createMask(5, 3) specific value for the test      
    */
    initPLRU(NULL, 0, 0, 3, createMask(5, 3));
    CU_ASSERT_EQUAL(extractIndex(address_hex[i]),extractIndex_expectedIndex[i]);
  }
}

void test_findVictim(void){
  initPLRU(dataStructure, DATASTRUCTURE_SIZE, NWAYS_ASSOCIATIVE, ADDRESS_OFFSET, createMask(ADDRESS_INDEX_SIZE, ADDRESS_OFFSET));

  for(int i = 0;i < NUMBER_OF_ADDRESSES_TESTED; i++){
    /*
      test with 6 bit of index, and a 8-way associative cashe    
    */
    uint16_t index = extractIndex(address_hex[i]);
    CU_ASSERT_EQUAL(findVictim(address_hex[i]),findVictim_expectedVictim[index]);
  }
}

void test_updateStatistics(void){
  initPLRU(dataStructure, DATASTRUCTURE_SIZE, NWAYS_ASSOCIATIVE, ADDRESS_OFFSET, createMask(ADDRESS_INDEX_SIZE, ADDRESS_OFFSET));
  for(int i = 0;i < NUMBER_OF_ADDRESSES_TESTED; i++){
    int randomCacheColumn = rand()%8;
    uint16_t address = address_hex[i];
    uint16_t index = extractIndex(address);
    uint32_t counter_mask = mask_counter_8wayAssociative[randomCacheColumn];
    uint32_t expected_counter = counterValue_8wayAssociative[randomCacheColumn];
    uint32_t counter = updateStatistics(address, randomCacheColumn);
    uint32_t interestedBitsCounter = counter & counter_mask;

    CU_ASSERT_EQUAL(interestedBitsCounter, expected_counter);    
  }
}

void test_invalidateStatistics(void){
  //INVALIDATESTATISTICS FOR PLRU DOES NOTHING
}

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
  srand(time(NULL));

   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   // NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() 
    if (NULL == CU_add_test(pSuite, "test of create mask", test_createMask)){
      CU_cleanup_registry();
      return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test of extract index", test_extractIndex)){
      CU_cleanup_registry();
      return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test of victim search", test_findVictim)){
      CU_cleanup_registry();
      return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test of update statistics", test_updateStatistics)){
      CU_cleanup_registry();
      return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test of invalidation of statistics", test_invalidateStatistics)){
      CU_cleanup_registry();
      return CU_get_error();
    }
    
   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   /*CU_set_output_filename("cunit.txt");
   CU_automated_run_tests();*/
   CU_cleanup_registry();
   return CU_get_error();
}

