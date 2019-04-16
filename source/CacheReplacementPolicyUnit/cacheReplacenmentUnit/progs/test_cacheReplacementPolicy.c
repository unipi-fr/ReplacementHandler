#include <stdio.h>  
#include <string.h>
#include <stdint.h>
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

uint16_t address_bin[64] = {
                          111000101100100, 1110001001110   , 11000011011010  , 110111111101    , 110011100111000 , 
                                111000011, 100011000000001 , 11100001110101  , 1110111001101110, 11110101001011  , 
                           10001010000001, 1001111100001   , 1011110101100101, 11001000111101  , 1110111101011110,
                            1111101010101, 1110100000010000, 1000010011011111, 101001000100001 , 1011001100011111,
                            1110100110010, 101011100101110 , 10111000100001  , 11101011100111  , 1010000101010011, 
                          110000110010100, 1100100001111110, 110101011110110 , 1100111000111000, 111011111011110 ,
                          100110100111100, 1011111110011101, 1010000101100   , 111111000010111 , 1100110110011010,
                          111101101100100, 1111111111011001, 1001001110011011, 1011001111011001, 1110111001001001, 
                          101000011100110, 101011001011010 , 1000001000101010, 1000111001001100, 1000100010011000,
                         1111000110001000, 1010110110100001, 1111000010101000, 111011001101001 , 1111111111000010, 
                         1010001111001000, 1001110011011   , 101011011110001 , 101000111101001 , 1100111010000010, 
                         111100001000100 , 1011001101111101, 1001011100000001, 110001100111011 , 110110111       , 
                         111011100000    , 1011000001110111, 1100000101010100, 1100100001111110
                       };


uint8_t expected_line_from_address[64] = { 0, 2, 0, 7, 3, 1, 0, 2, 6, 6, 0, 4, 
										   0, 7, 4, 6, 2, 4, 4, 4, 7, 6, 4, 1, 
										   3, 6, 0, 3, 3, 4, 7, 3, 5, 7, 0, 0, 
										   7, 0, 7, 5, 1, 0, 2, 1, 7, 5, 4, 1, 
										   1, 1, 5, 0, 6, 1, 1, 4, 7, 0, 4, 3, 
										   4, 3, 6, 0
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
		CU_ASSERT_EQUAL(check_adress_index(address_bin[i]),expected_line_from_address[i]);
	}
}

void test_findVictim(void){
  for(int i = 0; i < 64; i++){
    CU_ASSERT_EQUAL(findVictim(address_bin[i], model_1), expected_victim_model_1[expected_line_from_address[i]]);
  }
}





/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
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


   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   /*CU_set_output_filename("cunit.txt");
   CU_automated_run_tests();*/
   CU_cleanup_registry();
   return CU_get_error();
}

