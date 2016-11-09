#include <iostream>
#include "bst.hpp"
using namespace std;

// traversal of tree elements
void inorder_traversal(node *root)
{
    if(root == NULL)
        return;
    inorder_traversal(root->left);
    cout<<" "<<root->data<<" ";
    inorder_traversal(root->right);
}
void preorder_traversal(node *root)
{
    if(root == NULL)
        return;
    cout<<" "<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
void postorder_traversal(node *root)
{
    if(root == NULL)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<" "<<root->data<<" ";
}
