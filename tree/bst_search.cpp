#include <iostream>
#include "bst.hpp"
using namespace std;

// - search() - O(log n)
// Search and find data
node *search_node(node *root, int data)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data > data)
    {
        return(search_node(root->left,data));
    }
    else if (root->data < data)
    {
        return(search_node(root->right,data));
    }
    else
    {
        return root;
    }
}
