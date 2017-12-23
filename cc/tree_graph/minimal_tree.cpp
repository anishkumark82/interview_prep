/*
4.2 Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an algorithm
to create a binary search tree with minimal height.
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct _Node_t
{
    int data;
    struct _Node_t *left;
    struct _Node_t *right;
}Node_t;

// Function to create a node
Node_t *createNode(int data)
{
    Node_t *temp = new Node_t();
    temp->data = data;
    return temp;
}

Node_t *minimalTree(vector<int> V, int start, int end)
{
    Node_t *root;
    if(start <= end)
    {
        int node_idx = (start+end)/2;
        root = createNode(V[node_idx]);
        root->left  = minimalTree(V, start, node_idx-1);
        root->right = minimalTree(V, node_idx+1, end);
    }
    else
    {
        root = NULL;
    }
    return root;
}

void inOrdTrav(Node_t *root)
{
    //LNR
    if(root == NULL)
        return;
    inOrdTrav(root->left);
    cout<<root->data<<" ";
    inOrdTrav(root->right);
}

void postOrdTrav(Node_t *root)
{
    //NLR
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    postOrdTrav(root->left);
    postOrdTrav(root->right);
}
int main()
{
    vector<int> V = {1,3,5,6,9,12};
    Node_t *root = minimalTree(V, 0, V.size()-1);
    postOrdTrav(root);
    return 0;
}
