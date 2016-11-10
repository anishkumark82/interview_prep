#include <iostream>
#include "bst.hpp"
#include <stack>
using namespace std;

// Achieved by using 1 stack
// Time complexity - O(n)
// Space complexity - depends on how many nodes are there in stack -
//  -- O(h) where h is the height of the tree. Worst case O(n)
// Inorder traversal - Left->Visited(node)->Right
void inorder_iterative(node *root)
{
    // 1. If root is null return
    if(root == NULL)
        return;
    // 2. Create a stack
    stack<node *> S;

    // 3. Do while stack is not empty
    while((root != NULL) || (!S.empty()))
    {
        //4. If root node is not NULL push it into stack
        if(root)
        {
            S.push(root);
            //5. Then make root = root->left
            root = root->left;
        }
        else if(!S.empty())
        {
            //6. if root is NULL and stack not empty, Pop element from stack and print the element
            root = S.top();
            cout<<root->data<<" ";
            S.pop();

            //7. Make root = root->right
            root = root->right;
        }
    }
}

// Iterative pre-order traversing is achieved using a stack
// In case of Pre-order traversal nodes are visited in Visit(Node)->left->right
// Time complexity - O(n)
// Space complexity - depends on ht of the try.
//    -- Average Space complexity - O(h) and worst case O(n)
void preorder_iterative(node *root)
{
    if(root == NULL)
        return;

    // 1. Create a stack to store the node
    stack<node *> S1;
    // 2. Push the root node to the stack
    S1.push(root);
    // Do until the stack is empty
    while(!S1.empty())
    {
        // 3. Pop the top of the stack and print the top of the stack
        root = S1.top();
        S1.pop();

        cout<<root->data<<" ";
        //4. Node has a right child push into the stack
        if(root->right)
        {
            S1.push(root->right);
        }
        //5. Node has a left child push into the stack
        if(root->left)
        {
            S1.push(root->left);
        }
    }

}

// Achieved by using 2 stacks
// For Post order traversal nodes are displayed in Left->Right->Visited(node)
// Time complexity - O(n)
// Space complexity - O(n) - Since at the end Stack 2 will contain all the elements
void postorder_iterative(node *root)
{
    // If tree is empty return
    if(root == NULL)
        return;
    // 1. Create 2 stacks - Stack s1 and Stack s2
    stack<node *> S1,S2;
    // 2. Add root node to stack S1.
    S1.push(root);

    // 3. Keep looping until S1 is empty
    while(!S1.empty())
    {
        //4. Pop the top of S1 stack
        root = S1.top();
        S1.pop();

        //5. Push the element popped from S1 to S2
        S2.push(root);

        //6. if root has left push to stack S1
        if(root->left)
        {
            S1.push(root->left);
        }
        //7. if root has right push to stack S1
        if(root->right)
        {
            S1.push(root->right);
        }
    }// while(!S1.empty())

    //8. S2 should contain all the elements in post order.
    //   Pop and print elements in S2
    while(!S2.empty())
    {
        root = S2.top();
        cout<<root->data<<" ";
        S2.pop();
    }
}
