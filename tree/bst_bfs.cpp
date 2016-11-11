#include <iostream>
#include <queue>
#include <stack>

//#include <stdio.h>
#include "bst.hpp"
using namespace std;

// Complexity - O(n)
// Breadth first search
void bst_breadth_first_search(node *root)
{
    // if tree is empty return
    if(root == NULL)
    {
        return;
    }
    // Create a queue to store nodes and process nodes at each level
    queue<node *> Q;
    cout<<endl<<"breadth first search"<<endl;
    Q.push(root);
    while(!Q.empty())
    {
        node *current = Q.front();
        cout<<current->data<<" ";
        //cout<<"current->data : "<<current->data<<" ";
        //printf("current->left : %d", (current->left)?current->left->data:-1);
        //printf(" current->right : %d",(current->right)?current->right->data:-1);

        if(current->left)
        {
            Q.push(current->left);
        }
        if(current->right)
        {
            Q.push(current->right);
        }
        Q.pop();
    }
    return;
}
// Space complexity - O(n)
// Time complexity - O(n)
void bst_reverse_breadth_first_search(node *root)
{
    if(root == NULL)
        return;

    queue<node *>Q;
    stack<node *>S;
    Q.push(root);

    while(!Q.empty())
    {
        root = Q.front();
        Q.pop();

        S.push(root);

        // Right is pushed first since we are using a stack in the second round of operations
        if(root->right)
            Q.push(root->right);

        if(root->left)
            Q.push(root->left);
    }
    while(!S.empty())
    {
        cout<<S.top()->data<<" ";
        S.pop();
    }
}
