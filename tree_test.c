#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "CUnit/Basic.h"

#define GENERIC void*
#define INTEGER long int

#include "tree.h"

void test_tree_root ()
{
    BINARY_TREE* arv = BINARY_TREE_Create ();

    arv->root = TREE_NODE_Create (3);


    CU_ASSERT_EQUAL (TREE_Get_Node_Data (arv->root), 3);
}

void test_tree_children()
{
    BINARY_TREE* arv = BINARY_TREE_Create ();
    
    arv->root = TREE_NODE_Create_Merged (TREE_NODE_Create(2), TREE_NODE_Create(1));

    printf("%d\n",arv->root->left->data);
    printf("%d\n",arv->root->right->data);

    CU_ASSERT_EQUAL (TREE_Get_Node_Data (arv->root->left), 1);
    CU_ASSERT_EQUAL (TREE_Get_Node_Data (arv->root->right), 2);
}

int main ()
{
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry ())
      return CU_get_error ();
  
    CU_pSuite tree_test_root = NULL;
    CU_pSuite tree_test_children = NULL;
    // Add a suite to the registry
    tree_test_root = CU_add_suite ("Testing tree root", 0, 0);
    tree_test_children = CU_add_suite ("Testing tree root children", 0 ,0);

    CU_add_test (tree_test_root, "Testing tree root", test_tree_root);
    CU_add_test (tree_test_children, "Testing tree root children", test_tree_children);    
    
    // Sets the basic run mode, CU_BRM_VERBOSE will show maximum output of run details
    // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
    CU_basic_set_mode(CU_BRM_VERBOSE);

    // Run the tests and show the run summary
    CU_basic_run_tests();

    return CU_get_error();
}