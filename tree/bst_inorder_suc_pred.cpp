// Tree implementation

#include <iostream>
#include <new>
#include <climits>

using namespace std;
struct Node_t
{
    int data;
    struct Node_t *left;
    struct Node_t *right;
};

Node_t *getNode(int data)
{
    Node_t *temp = NULL;
    try
    {
        temp = new Node_t();
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
    temp->data  = data;
    temp->left  = NULL;
    temp->right = NULL;
    return temp;
}

// Insertion algorithm
Node_t *insertNode(Node_t *root, int data)
{
    if (root == NULL)
        root = getNode(data);
    else if (root->data > data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    return root;
}

Node_t *findMin(Node_t *root)
{
    // find the left most node
    if (root != NULL)
    {
        while (root->left)
            root = root->left;
    }
    return root;
}

Node_t *findMax(Node_t *root)
{
    // find the right most node
    if (root != NULL)
    {
        while (root->right)
            root = root->right;
    }
    return root;
}
// delete algorithm
Node_t *deleteNode(Node_t *root, int data)
{
    // three cases
    // 1. Node to be deleted is the leaf node -delete the node and set its parent's child link to NULL
    // 2. Node has only one child - delete the node and make its parent point to its child node
    // 3. Node has both left and right child
    if (root == NULL)
        return root;
    if (root->data > data)
        root->left = deleteNode(root->left, data);
    else if (root->data < data)
        root->right = deleteNode(root->right, data);
    else // found the node
    {
        // Case 1
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // Case 2
        else if (root->left == NULL)
        {
            Node_t *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node_t *temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3
        else
        {
            int successor = findMin(root->right)->data;
            root->data = successor;
            root->right = deleteNode(root->right, successor);
        }
    }
    return root;
}

// Find ht of a tree
// ht of the tree is the no: of edges in longest path from the root to a leaf node in the tree
int findHt(Node_t *root)
{
    if(root == NULL)
        return -1;
    return 1 + max(findHt(root->left), findHt(root->right));
}

// Search
Node_t *searchBST(Node_t *root, int data)
{
    if (root == NULL)
        return root;

    if(root->data == data)
        return root;
    if(root->data > data)
        return searchBST(root->left, data);
    return searchBST(root->right, data);
}

// Traversal
// Inorder
void inorderTrav(Node_t *root)
{
    if (root == NULL)
        return;
    // LNR
    inorderTrav(root->left);
    cout<<root->data<<" ";
    inorderTrav(root->right);
}
// Preorder
void preorderTrav(Node_t *root)
{
    if (root == NULL)
        return;
    // NLR
    cout<<root->data<<" ";
    preorderTrav(root->left);
    preorderTrav(root->right);
}
// Postorder
void postorderTrav(Node_t *root)
{
    if (root == NULL)
        return;
    // LRN
    postorderTrav(root->left);
    postorderTrav(root->right);
    cout<<root->data<<" ";
}

void inorderSuccessor(Node_t *root, Node_t **suc, int data)
{
    if (root == NULL)
        return;
    // 2 conditions
    // Node has a right subtree - inorder successor is the left most node in the right sub-tree
    // if no right subtree then find the ancestor node which has data in the right subtree

    if (root->data == data) /* found the node */
    {
        if(root->right)
            *suc = findMin(root->right);
    }
    else if (root->data > data) /* found the node */
    {
        *suc = root;
        inorderSuccessor(root->left, suc, data);
    }
    else
        inorderSuccessor(root->right, suc, data);
}

void inorderPred(Node_t *root, Node_t **pred, int data)
{
    if (root == NULL)
        return;
    // 2 conditions
    // Node has a left subtree - inorder pred is the right most node in the left sub-tree
    // if no left subtree then find the ancestor node which has data in the right subtree

    if (root->data == data) /* found the node */
    {
        if(root->left)
            *pred = findMax(root->left);
    }
    else if (root->data > data) /* found the node */
    {
        inorderPred(root->left, pred, data);
    }
    else
    {
        *pred = root;
        inorderPred(root->right, pred, data);
    }

}
int main()
{
    Node_t *root = NULL;
    root = insertNode(root, 100);
    root = insertNode(root, 110);
    root = insertNode(root, 120);
    root = insertNode(root, 90);
    root = insertNode(root, 95);
    root = insertNode(root, 115);
    root = insertNode(root, 150);
    root = insertNode(root, 140);
    root = insertNode(root, 75);
    root = insertNode(root, 85);

    cout<<"Inorder traversal : ";
    inorderTrav(root);
    cout<<"\nPreorder traversal : ";
    preorderTrav(root);
    cout<<"\nPostorder traversal : ";
    postorderTrav(root);
    cout<<endl;

    Node_t *found = searchBST(root, 150);
    cout<<"search node : 150 : " << found;
    found = searchBST(root, 200);
    cout<<"\nsearch node : 200 : " << found;

    cout<<"\nHeight of tree : "<<findHt(root);
/*
    root = deleteNode(root, 85);
    cout<<"Inorder traversal after 85 is deleted :";
    inorderTrav(root);
    cout<<endl;

    root = deleteNode(root, 150);
    cout<<"Inorder traversal after 150 is deleted :";
    inorderTrav(root);
    cout<<endl;

    root = deleteNode(root, 120);
    cout<<"Inorder traversal after 120 is deleted :";
    inorderTrav(root);
    cout<<endl;
*/
    Node_t *suc, *pred = NULL;
    inorderSuccessor(root, &suc, 100);
    inorderPred(root, &pred, 100);
    cout<<"\nSuccessor of 100 : ";
    if (suc)
    {
        cout<<suc->data<<endl;
    }
    else
    {
        cout<<"No successor"<<endl;
    }
    cout<<"\nPredecessor of 100 : ";
    if (pred)
    {
        cout<<pred->data<<endl;
    }
    else
    {
        cout<<"No Predecessor"<<endl;
    }


    suc = NULL, pred = NULL;
    inorderSuccessor(root, &suc, 90);
    inorderPred(root, &pred, 90);
    cout<<"\nSuccessor of 90 : ";
    if (suc)
    {
        cout<<suc->data<<endl;
    }
    else
    {
        cout<<"No successor"<<endl;
    }
    cout<<"\nPredecessor of 90 : ";
    if (pred)
    {
        cout<<pred->data<<endl;
    }
    else
    {
        cout<<"No Predecessor"<<endl;
    }

    suc = NULL, pred = NULL;
    inorderSuccessor(root, &suc, 85);
    inorderPred(root, &pred, 85);
    cout<<"\nSuccessor of 85 : ";
    if (suc)
    {
        cout<<suc->data<<endl;
    }
    else
    {
        cout<<"No successor"<<endl;
    }
    cout<<"\nPredecessor of 100 : ";
    if (pred)
    {
        cout<<pred->data<<endl;
    }
    else
    {
        cout<<"No Predecessor"<<endl;
    }

    suc = NULL, pred = NULL;
    inorderSuccessor(root, &suc, 110);
    inorderPred(root, &pred, 110);
    cout<<"\nSuccessor of 110 : ";
    if (suc)
    {
        cout<<suc->data<<endl;
    }
    else
    {
        cout<<"No successor"<<endl;
    }
    cout<<"\nPredecessor of 110 : ";
    if (pred)
    {
        cout<<pred->data<<endl;
    }
    else
    {
        cout<<"No Predecessor"<<endl;
    }

    suc = NULL, pred = NULL;
    inorderSuccessor(root, &suc, 150);
    inorderPred(root, &pred, 150);
    cout<<"\nSuccessor of 150 : ";
    if (suc)
    {
        cout<<suc->data<<endl;
    }
    else
    {
        cout<<"No successor"<<endl;
    }
    cout<<"\nPredecessor of 150 : ";
    if (pred)
    {
        cout<<pred->data<<endl;
    }
    else
    {
        cout<<"No Predecessor"<<endl;
    }

    return 0;
}
