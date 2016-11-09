#include <iostream>
#include <queue>
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
