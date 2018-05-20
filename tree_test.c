#include "header.h"

void Test_Tree_Root ()
{
    BINARY_TREE* tree = BINARY_TREE_Create ();

    tree->root = TREE_NODE_Create (3);

    CU_ASSERT_EQUAL (TREE_Get_Node_Data (tree->root), 3);
    return;
}

void Test_Tree_Children()
{
    BINARY_TREE* tree = BINARY_TREE_Create ();
    
    tree->root = TREE_NODE_Create_Merged (TREE_NODE_Create(2), TREE_NODE_Create(1));

    printf("%d\n",tree->root->left->data);
    printf("%d\n",tree->root->right->data);

    CU_ASSERT_EQUAL (TREE_Get_Node_Data (tree->root->left), 1);
    CU_ASSERT_EQUAL (TREE_Get_Node_Data (tree->root->right), 2);
    return;
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

    CU_add_test (tree_test_root, "Testing tree root", Test_Tree_Root);
    CU_add_test (tree_test_children, "Testing tree root children", Test_Tree_Children);    
    
    // Sets the basic run mode, CU_BRM_VERBOSE will show maximum output of run details
    // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
    CU_basic_set_mode(CU_BRM_VERBOSE);

    // Run the tests and show the run summary
    CU_basic_run_tests();

    return CU_get_error();
}