#include <iostream>
#include "bst.hpp"
using namespace std;

// Find the common ancestor for binary search tree
int bstFindCommonAncestor(node *root, int data1, int data2)
{
    if(root == NULL)
        return INT_MIN;

    if(data1 > data2)
    {
        // Swap to check for ancestor.
        data1 = data1 + data2; //data1 = data1 ^ data2;
        data2 = data1 - data2; //data2 = data1 ^ data2;
        data1 = data1 - data2; //data1 = data1 ^ data2;
    }
    // Assuming data1 is less than or equal to data2
    // if the node is greater than data1 and data2 then move to left
    // if node is less than data1 and data2 then move to right.
    // if node == data1 then data1 is the common ancestor
    // if data1 < node < data2 node->data is the common ancestor.
    // algorithm basically determines the node from which the data items took different path.

    if(((data1 < root->data) && (data2 > root->data)) ||
       (data1 == root->data) || (data2 == root->data))
       return root->data;

    if((data1 < root->data) && (data2 < root->data))
        return bstFindCommonAncestor(root->left, data1, data2);
    else
        return bstFindCommonAncestor(root->right, data1, data2);
}
