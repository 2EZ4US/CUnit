#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "CUnit/Basic.h"

#define GENERIC void*
#define INTEGER long int
#define MAX_HEAP_SIZE 10
#include "heap.h"

HEAP* build_heap_for_test ()
{
    HEAP* heap = HEAP_Create ();

    HEAP_Enqueue (heap, 500, is_greater);
    HEAP_Enqueue (heap, 400, is_greater);
    HEAP_Enqueue (heap, 800, is_greater);
    HEAP_Enqueue (heap, 600, is_greater);
    HEAP_Enqueue (heap, 'A', is_greater);
    return heap;       
}

void test_heap_size ()
{
  HEAP *heap = build_heap_for_test();
  CU_ASSERT_EQUAL (HEAP_Get_Size (heap), 5);
}

void test_heap_dequeue ()
{
  HEAP *heap = build_heap_for_test();
  CU_ASSERT_EQUAL (HEAP_Dequeue(heap,is_greater),'A');

}

void test_heap_parent ()
{
  HEAP* heap = build_heap_for_test ();
  CU_ASSERT_EQUAL (HEAP_Get_Data(heap, HEAP_Get_Parent(5)), 400);
}

int main ()
{
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry ())
      return CU_get_error ();
  
    CU_pSuite heap_test_size = NULL;
    CU_pSuite heap_test_dequeue = NULL;
    CU_pSuite heap_test_parent = NULL;
    
    // Add a suite to the registry
    heap_test_size = CU_add_suite ("Testing heap size", 0, 0);
    heap_test_dequeue = CU_add_suite ("Testing heap dequeue", 0, 0);
    heap_test_parent = CU_add_suite ("Testing heap parent", 0, 0);

    CU_add_test (heap_test_size, "Testing heap size", test_heap_size);
    CU_add_test (heap_test_dequeue, "Testing heap dequeue", test_heap_dequeue);
    CU_add_test (heap_test_parent, "Testing heap parent ", test_heap_parent);
    
    // Sets the basic run mode, CU_BRM_VERBOSE will show maximum output of run details
    // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
    CU_basic_set_mode(CU_BRM_VERBOSE);

    // Run the tests and show the run summary
    CU_basic_run_tests();

    return CU_get_error();
   	return 0;
}