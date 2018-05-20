#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "CUnit/Basic.h"

#define GENERIC void*
#define INTEGER long int

#include "deque.h"


LIST* build_list_for_test ()
{
   LIST* list = LIST_Create ();
   LIST_Insert_Tail (list, 4);
   LIST_Insert_Tail (list, 3);
   LIST_Insert_Tail (list, 2);
   LIST_Insert_Tail (list, 9);

   return list;
}

void test_list_insert ()
{
  LIST* list = build_list_for_test ();

  CU_ASSERT_EQUAL (list->size, 4);
  CU_ASSERT_EQUAL (list->head->data, 4);
  CU_ASSERT_EQUAL (list->tail->data, 9);
}

void test_list_remove ()
{
  LIST* list = build_list_for_test ();

  LIST_Remove_Tail (list);
  CU_ASSERT_EQUAL (list->tail->data, 2);
}

int main ()
{
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry ())
      return CU_get_error ();
  
    CU_pSuite list_test_insert = NULL;
    CU_pSuite list_test_remove = NULL;
    // Add a suite to the registry
    list_test_insert = CU_add_suite ("Testing List Insert", 0, 0);
    list_test_remove = CU_add_suite ("Testing List Remove", 0 ,0);

    CU_add_test (list_test_insert, "Testing List Insert", test_list_insert);
    CU_add_test (list_test_remove, "Testing List Remove", test_list_remove);
    
    // Sets the basic run mode, CU_BRM_VERBOSE will show maximum output of run details
    // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
    CU_basic_set_mode(CU_BRM_VERBOSE);

    // Run the tests and show the run summary
    CU_basic_run_tests();

    return CU_get_error();
    return 0;
}