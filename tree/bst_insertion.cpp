#include <iostream>
#include "bst.hpp"
using namespace std;

// - insert() - O(log n)
// Insert the data and return the root node
node *insert_node(node* root, int data)
{
    if(root == NULL)
    {
        root = create_node(data);
    }
    else if(root->data >= data)
    {
        root->left = insert_node(root->left, data);
    }
    else
    {
        root->right = insert_node(root->right, data);
    }
    return root;
}
