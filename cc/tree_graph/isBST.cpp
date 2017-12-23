/*
4.5 Validate BST: Implement a function to check if a binary tree is a binary search tree.
*/

#include<iostream>
#include<algorithm>
#include<climits>

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

Node_t *insertNode(Node_t *root, int data)
{
    if(root == NULL)
    {
        root = createNode(data);
    }
    else if(root->data >= data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
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

bool isBSTUtil(Node_t *root, int min_val, int max_val)
{
    if(root == NULL) return true;
    return ((root->data > min_val) && (root->data < max_val) &&
            isBSTUtil(root->left, min_val, root->data) &&
            isBSTUtil(root->right, root->data, max_val));

}
bool isBST(Node_t *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
int main()
{
    Node_t *root = NULL;

    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 9);
    root = insertNode(root, 8);

    // Display the nodes of the tree
    cout<<"Nodes of the tree"<<endl;
    postOrdTrav(root);
    cout<<endl;

    cout<<isBST(root)<<endl;

    return 0;
}
