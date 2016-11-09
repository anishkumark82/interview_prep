// Program to determine the number of nodes in a binary tree
#include "bst.hpp"
#include <iostream>
using namespace std;

// Time complexity - O(n)

int bt_size(node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    return 1 + bt_size(root->left) + bt_size(root->right);
}
