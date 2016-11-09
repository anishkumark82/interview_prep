#include <iostream>
#include "bst.hpp"
using namespace std;
// Find ht of a tree
int find_ht(node *root)
{
    if(root == NULL)
    {
        return -1;
    }
    return MAX(find_ht(root->left), find_ht(root->right)) + 1;
}
