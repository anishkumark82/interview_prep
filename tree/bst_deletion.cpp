#include <iostream>
#include "bst.hpp"
using namespace std;

// - delete() - O(log n)
// delete a node from the tree
// Three cases
// 1. Node to be deleted is a leaf node
// 2. Node to be deleted has only one child (left or right)
// 3. Node to be deleted has both children
node *delete_node(node *root, int data)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data > data)
    {
        root->left = delete_node(root->left, data);
    }
    else if(root->data < data)
    {
        root->right = delete_node(root->right, data);
    }
    else // Found the node to be deleted
    {
        if(!root->left && !root->right) // Case 1
        {
            delete root;
            root = NULL;
        }
        else if(!root->left) // Case 2
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(!root->right) // Case 2
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        else // Case 3
        {
            int min_data = findMin(root->right);
            root->data = min_data;
            delete_node(root->right, min_data);
        }
    }
    return root;
}
