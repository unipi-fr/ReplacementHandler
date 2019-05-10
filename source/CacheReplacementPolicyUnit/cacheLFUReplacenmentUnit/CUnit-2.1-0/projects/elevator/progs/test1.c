
#include <stdio.h>  
#include <string.h>
#include "CUnit/Basic.h"
#include "types.h"
#include "cabin.h"
#include "globals.h"

void EE_lcd_putc (char a){
  fprintf (stderr, "Door is '%c'", a);
}
void EE_lcd_goto (int a , int b) {
  fprintf (stderr, "I am in (X, Y) = (%d, %d)", a, b);
};



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

void testInit(void)
{
   Cabin cbn;
   CabinInit(&cbn);
   CU_ASSERT(0 == isopen);
}

void testCabinDispatch(void)
{
  Cabin cbn;
  CabinInit(&cbn);
  CabinTran_(&cbn, 2);
  open = 0;
  close = 1;
  CabinDispatch (&cbn); 
  CU_ASSERT(cbn.state_ == 3);
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
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if ((NULL == CU_add_test(pSuite, "test of CabinInit(Cabin *)", testInit)) 
       || (NULL == CU_add_test(pSuite, "test of CabinDispatch(Cabin *)", testCabinDispatch)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }



   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

