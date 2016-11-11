#include <iostream>
#include "bst.hpp"
#include <queue>
using namespace std;
// Print nodes in each level using 2 queues
void bt_level_print_1(node *root)
{
    if(root == NULL)
        return;
    // Create 2 queues
    queue<node *>Q1,Q2;
    // Push root node to Q1 queue
    Q1.push(root);
    // While atleast one queue is not empty do the following steps
    while(!Q1.empty() || !Q2.empty())
    {
        cout<<endl;
        // while elements are in Q1 pop the node and print the node
        // (all the nodes in current queue will be in same level)
        // push the left and right node into the queue Q2
        while(!Q1.empty())
        {
            root = Q1.front();
            cout<<root->data<<" ";
            Q1.pop();
            if(root->left)
                Q2.push(root->left);
            if(root->right)
                Q2.push(root->right);
        }
        cout<<endl;
        // while elements are in Q2 pop the node and print the node
        // (all the nodes in current queue will be in same level)
        // push the left and right node into the queue Q1
        while(!Q2.empty())
        {
            root = Q2.front();
            cout<<root->data<<" ";
            Q2.pop();
            if(root->left)
                Q1.push(root->left);
            if(root->right)
                Q1.push(root->right);
        }
    }


}

// Print nodes in each level using 1 queue and delimiter
void bt_level_print_2(node *root)
{
    if(root == NULL)
        return;
    // Create 1 queue
    queue<node *>Q1;
    // Push root node and delimiter into Q1 queue
    Q1.push(root);
    Q1.push(NULL);
    // Do while the queue is not empty
    while(!Q1.empty())
    {
        // Pop the front of the queue
        root = Q1.front();
        Q1.pop();
        // if root is not the null delimiter push left and right to the queue
        if(root != NULL)
        {
            cout<<root->data<<" ";
            if(root->left)
                Q1.push(root->left);
            if(root->right)
                Q1.push(root->right);
        }
        else
        {
            // if root is null delimiter print endl and if the queue is not empty push the delimiter
            cout<<endl;
            if(!Q1.empty())
            {
                Q1.push(NULL);
            }
        }
    }
}

