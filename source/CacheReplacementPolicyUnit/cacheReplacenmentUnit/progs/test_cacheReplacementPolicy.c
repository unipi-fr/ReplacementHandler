#include <stdio.h>  
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include </home/edoardo/Scrivania/CacheReplacementPolicyUnit/cacheReplacenmentUnit/CUnit-2.1-0/CUnit/Headers/Basic.h>
#include </home/edoardo/Scrivania/CacheReplacementPolicyUnit/cacheReplacenmentUnit/CUnit-2.1-0/CUnit/Headers/Automated.h>
#include "replacement.h"




uint8_t model_1[64] = { 105, 21, 54, 120, 204, 188, 239, 93, 50, 166, 235, 150, 
                    218, 243, 0, 66, 36, 111, 126, 97, 119, 221, 163, 134, 
                    147, 196, 202, 6, 235, 216, 5, 212, 109, 186, 77, 58, 
                    247, 61, 151, 42, 99, 3, 192, 190, 118, 192, 1, 26, 
                     49, 1, 123, 40, 221, 31, 46, 241, 100, 121, 119, 207, 
                     82, 124, 164, 191
                   };

uint8_t model_2[64] = { 253, 67, 253, 13, 145, 35, 47, 212, 95, 93, 168, 55, 
                     31, 54, 110, 51, 240, 211, 17, 140, 125, 144, 174, 107, 
                    134, 159, 81, 132, 137, 248, 5, 135, 187, 3, 148, 78, 
                    166, 196, 35, 133, 161, 75, 60, 192, 1, 170, 243, 241, 
                    126, 5, 126, 123, 149, 173, 231, 155, 204, 184, 33, 86, 
                     49, 38, 93, 236
                   };

uint8_t model_3[64] = { 249, 253, 136, 38, 242, 224, 49, 79, 118, 174, 192, 236, 
                    243, 119, 210, 146, 109, 218, 50, 128, 184, 142, 43, 206, 
                    125, 73, 199, 95, 174, 106, 75, 40, 231, 83, 79, 218, 
                     52, 1, 42, 42, 46, 235, 24, 35, 226, 106, 181, 81, 
                    196, 104, 81, 125, 246, 251, 203, 117, 70, 148, 84, 116, 
                    126, 31, 156, 102
                   };


uint8_t model_4[64] = {  44, 11, 134, 180, 217, 159, 13, 49, 84, 183, 183, 208, 
                    132, 119, 93, 237, 167, 75, 10, 179, 34, 175, 233, 163, 
                     66, 148, 163, 68, 185, 44, 119, 230, 182, 125, 27, 144, 
                    157, 167, 66, 241, 96, 121, 66, 228, 240, 31, 83, 153, 
                    106, 93, 77, 12, 13, 55, 176, 207, 203, 84, 147, 5, 
                    128, 138, 107, 182
                   };


uint8_t model_5[64] = { 231, 88, 241, 59, 7, 87, 77, 197, 41, 252, 224, 246, 
                    134, 107, 49, 63, 108, 122, 48, 51, 215, 214, 194, 86, 
                      1, 187, 132, 190, 18, 60, 226, 249, 21, 212, 54, 28, 
                    171, 131, 98, 212, 1, 67, 76, 6, 47, 125, 69, 27, 
                    247, 245, 79, 79, 204, 145, 165, 204, 204, 43, 11, 223,   
                    230, 237, 89, 251
                   };



uint8_t model_1_copy[64] = { 105, 21, 54, 120, 204, 188, 239, 93, 50, 166, 235, 150, 
                    218, 243, 0, 66, 36, 111, 126, 97, 119, 221, 163, 134, 
                    147, 196, 202, 6, 235, 216, 5, 212, 109, 186, 77, 58, 
                    247, 61, 151, 42, 99, 3, 192, 190, 118, 192, 1, 26, 
                     49, 1, 123, 40, 221, 31, 46, 241, 100, 121, 119, 207, 
                     82, 124, 164, 191
                   };

uint8_t model_2_copy[64] = { 253, 67, 253, 13, 145, 35, 47, 212, 95, 93, 168, 55, 
                     31, 54, 110, 51, 240, 211, 17, 140, 125, 144, 174, 107, 
                    134, 159, 81, 132, 137, 248, 5, 135, 187, 3, 148, 78, 
                    166, 196, 35, 133, 161, 75, 60, 192, 1, 170, 243, 241, 
                    126, 5, 126, 123, 149, 173, 231, 155, 204, 184, 33, 86, 
                     49, 38, 93, 236
                   };

uint8_t model_3_copy[64] = { 249, 253, 136, 38, 242, 224, 49, 79, 118, 174, 192, 236, 
                    243, 119, 210, 146, 109, 218, 50, 128, 184, 142, 43, 206, 
                    125, 73, 199, 95, 174, 106, 75, 40, 231, 83, 79, 218, 
                     52, 1, 42, 42, 46, 235, 24, 35, 226, 106, 181, 81, 
                    196, 104, 81, 125, 246, 251, 203, 117, 70, 148, 84, 116, 
                    126, 31, 156, 102
                   };


uint8_t model_4_copy[64] = {  44, 11, 134, 180, 217, 159, 13, 49, 84, 183, 183, 208, 
                    132, 119, 93, 237, 167, 75, 10, 179, 34, 175, 233, 163, 
                     66, 148, 163, 68, 185, 44, 119, 230, 182, 125, 27, 144, 
                    157, 167, 66, 241, 96, 121, 66, 228, 240, 31, 83, 153, 
                    106, 93, 77, 12, 13, 55, 176, 207, 203, 84, 147, 5, 
                    128, 138, 107, 182
                   };


uint8_t model_5_copy[64] = { 231, 88, 241, 59, 7, 87, 77, 197, 41, 252, 224, 246, 
                    134, 107, 49, 63, 108, 122, 48, 51, 215, 214, 194, 86, 
                      1, 187, 132, 190, 18, 60, 226, 249, 21, 212, 54, 28, 
                    171, 131, 98, 212, 1, 67, 76, 6, 47, 125, 69, 27, 
                    247, 245, 79, 79, 204, 145, 165, 204, 204, 43, 11, 223,   
                    230, 237, 89, 251
                   };


uint8_t expected_updated_statistic_1[64] = {  112,  28,  61, 127, 211, 195, 246, 100,
                                               56, 172, 241, 156, 224, 249,   6,  72,
                                               42, 117, 132, 103, 125, 227, 169, 140,
                                              160, 209, 215,  19, 248, 229,  18, 225,
                                              119, 196,  87,  68, 255,  71, 161,  52,
                                              106,  10, 199, 197, 125, 199,   8,  33,
                                               55,   7, 129,  46, 227,  37,  52, 247,
                                              109, 130, 128, 216,  91, 133, 173, 200 
                                           };


uint8_t expected_updated_statistic_2[64] = {  255,  74, 255,  20, 152,  42,  54, 219, 
                                              101,  99, 174,  61,  37,  60, 116,  57,
                                              246, 217,  23, 146, 131, 150, 180, 113,
                                              147, 172,  94, 145, 150, 255,  18, 148,
                                              197,  13, 158,  88, 176, 206,  45, 143,
                                              168,  82,  67, 199,   8, 177, 250, 248,
                                              132,  11, 132, 129, 155, 179, 237, 161,
                                              213, 193,  42,  95,  58,  47, 102, 245 
                                           };


uint8_t expected_updated_statistic_3[64] = {  255, 255, 143,  45, 249, 231,  56,  86,
                                              124, 180, 198, 242, 249, 125, 216, 152,
                                              115, 224,  56, 134, 190, 148,  49, 212,
                                              138,  86, 212, 108, 187, 119,  88,  53,
                                              241,  93,  89, 228,  62,  11,  52,  52,
                                               53, 242,  31,  42, 233, 113, 188,  88,
                                              202, 110,  87, 131, 252, 255, 209, 123,
                                               79, 157,  93, 125, 135,  40, 165, 111 
                                           };



uint8_t expected_updated_statistic_4[64] = {   51,  18, 141, 187, 224, 166,  20,  56,
                                               90, 189, 189, 214, 138, 125,  99, 243,
                                              173,  81,  16, 185,  40, 181, 239, 169,
                                               79, 161, 176,  81, 198,  57, 132, 243,
                                              192, 135,  37, 154, 167, 177,  76, 251,
                                              103, 128,  73, 235, 247,  38,  90, 160,
                                              112,  99,  83,  18,  19,  61, 182, 213,
                                              212,  93, 156,  14, 137, 147, 116, 191
                                           };



uint8_t expected_updated_statistic_5[64] = { 238,  95, 248,  66,  14,  94,  84, 204,
                                              47, 255, 230, 252, 140, 113,  55,  69, 
                                             114, 128,  54,  57, 221, 220, 200,  92,
                                              14, 200, 145, 203,  31,  73, 239, 255,
                                              31, 222,  64,  38, 181, 141, 108, 222,
                                               8,  74,  83,  13,  54, 132,  76,  34, 
                                             253, 251,  85,  85, 210, 151, 171, 210,
                                             213,  52,  20, 232, 239, 246,  98, 255 
                                           };



uint8_t expected_invalidated_statistic_1[64] = {   0,   0,  0,   0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 36,
                                                 111, 126, 97, 119, 221, 163, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,
                                                   0,   0,  0,   0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,
                                                   0,   0,  0,   0,   0,   0,   0, 0, 0, 0, 0, 0, 0 
                                               };



uint8_t expected_invalidated_statistic_2[64] = {   0,   0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 240, 211, 17, 
                                                 140, 125, 144, 174, 107, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  0,
                                                   0,   0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  0,
                                                   0,   0,   0,   0,   0, 0, 0 
                                               };


uint8_t expected_invalidated_statistic_3[64] = {   0,  0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109, 218,  50, 128, 184,
                                                 142, 43, 206, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,
                                                   0,  0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0  
                                               };


uint8_t expected_invalidated_statistic_4[64] = {   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 167, 75, 10, 179, 34, 175,
                                                 233, 163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,  0,  0,   0,  0,   0,
                                                   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0, 0, 0
                                               };



uint8_t expected_invalidated_statistic_5[64] = {   0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 122, 48, 51, 215, 214,
                                                 194, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  0,  0,   0,   0,
                                                   0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  0, 0 
                                               };





uint16_t address_hex[64] = {  0x7164, 0x1c4e, 0x30da, 0xdfd, 0x6738, 0x1c3, 0x4601, 0x3875, 0xee6e, 0x3d4b, 0x2281, 0x13e1, 
                          0xbd65, 0x323d, 0xef5e, 0x1f55, 0xe810, 0x84df, 0x5221, 0xb31f, 0x1d32, 0x572e, 0x2e21, 0x3ae7, 
                          0xa153, 0x6194, 0xc87e, 0x6af6, 0xce38, 0x77de, 0x4d3c, 0xbf9d, 0x142c, 0x7e17, 0xcd9a, 0x7b64, 
                          0xffd9, 0x939b, 0xb3d9, 0xee49, 0x50e6, 0x565a, 0x822a, 0x8e4c, 0x8898, 0xf188, 0xada1, 0xf0a8, 
                          0x7669, 0xffc2, 0xa3c8, 0x139b, 0x56f1, 0x51e9, 0xce82, 0x7844, 0xb37d, 0x9701, 0x633b, 0x1b7, 
                           0xee0, 0xb077, 0xc154, 0xc87e
                        };


uint16_t address_dec[64] = { 
                          29028, 7246, 12506, 3581, 26424, 451, 17921, 14453, 61038, 15691, 8833, 5089, 
                          48485, 12861, 61278, 8021, 59408, 34015, 21025, 45855, 7474, 22318, 11809, 15079, 
                          41299, 24980, 51326, 27382, 52792, 30686, 19772, 49053, 5164, 32279, 52634, 31588, 
                          65497, 37787, 46041, 61001, 20710, 22106, 33322, 36428, 34968, 61832, 44449, 61608, 
                          30313, 65474, 41928, 5019, 22257, 20969, 52866, 30788, 45949, 38657, 25403, 439, 
                           3808, 45175, 49492, 51326

                        };



uint8_t expected_line_from_address[64] = { 4, 1, 3, 7, 7, 0, 0, 6, 5, 1, 0, 4, 
										   4, 7, 3, 2, 2, 3, 4, 3, 6, 5, 4, 4, 
										   2, 2, 7, 6, 7, 3, 7, 3, 5, 2, 3, 4, 
										   3, 3, 3, 1, 4, 3, 5, 1, 3, 1, 4, 5, 
										   5, 0, 1, 3, 6, 5, 0, 0, 7, 0, 7, 6, 
										   4, 6, 2, 7
										  };



uint8_t expected_victim_model_1[8] = { 1, 6, 0, 6, 7, 6, 1, 4 };

uint8_t expected_victim_model_2[8] = { 3, 4, 2, 6, 1, 4, 1, 2 };

uint8_t expected_victim_model_3[8] = { 3, 0, 6, 7, 5, 2, 2, 5 };

uint8_t expected_victim_model_4[8] = { 1, 0, 2, 5, 2, 5, 3, 3 };

uint8_t expected_victim_model_5[8] = { 4, 0, 2, 0, 0, 0, 2, 2 };





/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite1(void)
{

  printf ("\nInitializing suite1\n");
  return 0;
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void)
{
  printf ("\nCompleting suite1\n");
  return 0;
}


void test_findCorrectLine(void){
	for(int i = 0; i < 64; i++){
		CU_ASSERT_EQUAL(check_adress_index(address_dec[i]),expected_line_from_address[i]);
	}
}

void test_findVictim(void){
  for(int i = 0; i < 64; i++){

    if( i == IDX_1 || i == IDX_2 || i == IDX_3 ){
      CU_ASSERT_NOT_EQUAL(findVictim(address_dec[i], model_1), expected_victim_model_1[expected_line_from_address[i]] + MIN_RAND + rand()%MAX_RAND);
      CU_ASSERT_NOT_EQUAL(findVictim(address_dec[i], model_2), expected_victim_model_2[expected_line_from_address[i]] + MIN_RAND + rand()%MAX_RAND);
      CU_ASSERT_NOT_EQUAL(findVictim(address_dec[i], model_3), expected_victim_model_3[expected_line_from_address[i]] + MIN_RAND + rand()%MAX_RAND);
      CU_ASSERT_NOT_EQUAL(findVictim(address_dec[i], model_4), expected_victim_model_4[expected_line_from_address[i]] + MIN_RAND + rand()%MAX_RAND);
      CU_ASSERT_NOT_EQUAL(findVictim(address_dec[i], model_5), expected_victim_model_5[expected_line_from_address[i]] + MIN_RAND + rand()%MAX_RAND);
    }
   
    CU_ASSERT_EQUAL(findVictim(address_dec[i], model_1), expected_victim_model_1[expected_line_from_address[i]]);
    CU_ASSERT_EQUAL(findVictim(address_dec[i], model_2), expected_victim_model_2[expected_line_from_address[i]]);
    CU_ASSERT_EQUAL(findVictim(address_dec[i], model_3), expected_victim_model_3[expected_line_from_address[i]]);
    CU_ASSERT_EQUAL(findVictim(address_dec[i], model_4), expected_victim_model_4[expected_line_from_address[i]]);
    CU_ASSERT_EQUAL(findVictim(address_dec[i], model_5), expected_victim_model_5[expected_line_from_address[i]]);
    
  }
}



void test_updateStatistics(void){


    for(int i = 0; i < 64; i++){
      for(int k = 0; k < 8; k++){
          updateStatistics(address_dec[i], k, model_1_copy);
          updateStatistics(address_dec[i], k, model_2_copy);
          updateStatistics(address_dec[i], k, model_3_copy);
          updateStatistics(address_dec[i], k, model_4_copy);
          updateStatistics(address_dec[i], k, model_5_copy);
      }
    }


    for(int i = 0; i < 64; i++){
        CU_ASSERT_EQUAL(model_1_copy[i], expected_updated_statistic_1[i]);   
        CU_ASSERT_EQUAL(model_2_copy[i], expected_updated_statistic_2[i]);  
        CU_ASSERT_EQUAL(model_3_copy[i], expected_updated_statistic_3[i]);  
        CU_ASSERT_EQUAL(model_4_copy[i], expected_updated_statistic_4[i]); 
        CU_ASSERT_EQUAL(model_5_copy[i], expected_updated_statistic_5[i]); 
    }
          

    //ripristino i valori uguali a quelli iniziali per usare i vettori "copy" in altri test 
    for(int i = 0; i < 64; i++){
        model_1_copy[i] = model_1[i];   
        model_2_copy[i] = model_2[i];   
        model_3_copy[i] = model_3[i];   
        model_4_copy[i] = model_4[i];   
        model_5_copy[i] = model_5[i];   
  
    }




}




void test_invalidateStatistics(void){

    for(int i = 0; i < INVALIDATE_UB; i++){
      for(int k = 0; k < 8; k++){
          invalidateStatistics(address_dec[i], k, model_1_copy);
          invalidateStatistics(address_dec[i], k, model_2_copy);
          invalidateStatistics(address_dec[i], k, model_3_copy);
          invalidateStatistics(address_dec[i], k, model_4_copy);
          invalidateStatistics(address_dec[i], k, model_5_copy);
      }
    }

    for(int i = 0; i < 64; i++){
        CU_ASSERT_EQUAL(model_1_copy[i], expected_invalidated_statistic_1[i]);  
        CU_ASSERT_EQUAL(model_2_copy[i], expected_invalidated_statistic_2[i]); 
        CU_ASSERT_EQUAL(model_3_copy[i], expected_invalidated_statistic_3[i]);  
        CU_ASSERT_EQUAL(model_4_copy[i], expected_invalidated_statistic_4[i]); 
        CU_ASSERT_EQUAL(model_5_copy[i], expected_invalidated_statistic_5[i]);     
    }    


}



void test_randomPolicy(void){

  for(int i = 0; i< MAX_RANDOM_TEST; i++){
    CU_ASSERT_TRUE(randomPolicy() < MAX_CACHE_ELEMENTS);
  }

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
    if (NULL == CU_add_test(pSuite, "test of find expected line", test_findCorrectLine)){
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
    if (NULL == CU_add_test(pSuite, "test of random policy", test_randomPolicy)){
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

