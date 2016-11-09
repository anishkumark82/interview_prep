#include <iostream>
#include "bst.hpp"
using namespace std;

// Find min node
int findMin(node *root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }
    if(root->left)
    {
        return(findMin(root->left));
    }
    return root->data;
}
// Find max node
int findMax(node *root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }
    if(root->right)
    {
        return(findMin(root->right));
    }
    return root->data;
}

