#ifndef TREE_AHRT
#define TREE_AHRT

typedef struct TREE_NODE {
    GENERIC data;
    struct TREE_NODE *left, *right;
} TREE_NODE;

typedef struct BINARY_TREE {
    struct TREE_NODE *root;
    INTEGER size;
} BINARY_TREE;

GENERIC BINARY_TREE_Create() {
    BINARY_TREE *new_tree = (BINARY_TREE*) malloc(sizeof(BINARY_TREE));
    new_tree->root = NULL;
    new_tree->size = 0;
    return new_tree;
}

GENERIC TREE_NODE_Create(GENERIC data) {
    TREE_NODE *new_node = (TREE_NODE*) malloc(sizeof(TREE_NODE));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

GENERIC TREE_NODE_Create_Merged(GENERIC right, GENERIC left) {
    TREE_NODE *new_node = (TREE_NODE*) malloc(sizeof(TREE_NODE));
    new_node->left = left;
    new_node->right = right;
    return new_node;
}


GENERIC TREE_Get_Node_Data (TREE_NODE* node) {   
    return node->data;
}

#endif
