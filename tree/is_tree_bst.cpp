#include <iostream>
#include "bst.hpp"
using namespace std;

// Check if a tree is a binary search tree
bool isBSTUtil(node *root, int min_value, int max_value)
{
    if(root == NULL)
        return true;

    return((root->data > min_value && root->data < max_value) &&
           (isBSTUtil(root->left, min_value, root->data)) &&
           (isBSTUtil(root->right,root->data, max_value)));
}

bool isBST(node *root)
{
    return (isBSTUtil(root, INT_MIN, INT_MAX));
}
