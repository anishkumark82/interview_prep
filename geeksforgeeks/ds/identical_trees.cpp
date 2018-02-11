// C++ program to check if two trees are mirror
// of each other
#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to
   left child and a pointer to right child */
struct Node
{
    int data;
    Node* left, *right;
};

/* Given two trees, return true if they are
   mirror of each other */
int areIdentical(Node* a, Node* b)
{
    if(a == NULL && b == NULL)
    {
        return true;
    }

    if(a == NULL || b == NULL)
    {
        return false;
    }

    return (a->data == b->data) && areIdentical(a->left, b->left) &&
            areIdentical(a->right, b->right);

}


int areStructuralIdentical(Node *a, Node *b)
{
    if(a == NULL && b == NULL)
    {
        return true;
    }
    if(a == NULL || b == NULL)
    {
        return false;
    }

    return areStructuralIdentical(a->left, b->left) &&
        areStructuralIdentical(a->right, b->right);
}
/* Helper function that allocates a new node */
Node* newNode(int data)
{
    Node* node = new Node;
    node->data  = data;
    node->left  =  node->right  = NULL;
    return(node);
}

/* Driver program to test areMirror() */
int main()
{
    Node *a = newNode(1);
    Node *b = newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);
    a->left->left  = newNode(4);
    a->left->right = newNode(5);

    b->left = newNode(2);
    b->right = newNode(3);
    b->left->left  = newNode(4);
    b->left->right = newNode(5);

    areIdentical(a, b)? cout << "Yes" : cout << "No";
    cout<<endl;
    areStructuralIdentical(a, b)? cout << "Yes" : cout << "No";
    cout<<endl;
    return 0;
}
