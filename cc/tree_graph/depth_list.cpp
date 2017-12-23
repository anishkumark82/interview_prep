/*
4.3 List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes
at each depth (e.g., if you have a tree with depth D, you 'll have D linked lists).
*/

#include<iostream>
#include<list>
#include<algorithm>

#define MAX_TREE_DEPTH 10
using namespace std;
typedef struct _Node_t
{
    int data;
    struct _Node_t *left;
    struct _Node_t *right;
}Node_t;

void treeDepthList(Node_t *root, list<Node_t *> depthList[MAX_TREE_DEPTH], int &depth)
{
    list<Node_t *> Q;
    depth = 0;
    if(root == NULL) return;

    Q.push_back(root);

    list<Node_t *>::iterator QItr = Q.begin();
    while(QItr != Q.end())
    {
        cout<<"Processing Queue at depth :: "<<depth<<endl;
        // All the current nodes are in the same level process all the nodes in that level
        Q.splice(depthList[depth].begin(), depthList[depth], Q.begin(), Q.end());
        list<Node_t *>::iterator parentItr;
        for(parentItr = depthList[depth].begin(); parentItr != depthList[depth].end(); parentItr++)
        {
            if((*parentItr)->left)
            {
                Q.push_back((*parentItr)->left);
            }
            if((*parentItr)->right)
            {
                Q.push_back((*parentItr)->right);
            }
        }
        QItr = Q.begin();
        depth++;
    }
}

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

    list<Node_t *> depthList[MAX_TREE_DEPTH];
    int depth = 0;
    treeDepthList(root, depthList, depth);

    for(int i = 0; i < depth; i++)
    {
        list<Node_t *>::iterator dItr;
        cout<<"depth = "<<i<<endl;
        for(dItr = depthList[i].begin(); dItr != depthList[i].end(); dItr++)
        {
            cout<<(*dItr)->data<<" ";
        }
        cout<<endl;
    }
    return 0;
}
