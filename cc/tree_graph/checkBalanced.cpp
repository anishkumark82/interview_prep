/*4.4 Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of
this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any
node never differ by more than one.
*/
#include<iostream>
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

int isTreeBalancedUtil(Node_t *root, bool &isBalanced)
{
    if(root == NULL)
    {
        return -1;
    }
    if(isBalanced)
    {
        int r_ht = isTreeBalancedUtil(root->right, isBalanced);
        int l_ht = 0;
        if(isBalanced)
        {
            l_ht = isTreeBalancedUtil(root->left, isBalanced);
        }

        if(isBalanced)
        {
            cout<<"difference of ht of tree : "<<"r_ht, l_ht, diff : "<<r_ht<<" , "<<l_ht<<" , "<<abs(r_ht - l_ht)<<endl;
            if(abs(r_ht - l_ht) > 1)
            {
                isBalanced = false;
            }
            else
            {
                return (1 + max(r_ht, l_ht));
            }
        }
    }
    return -1;
}
bool isTreeBalanced(Node_t *root)
{
    bool isBalanced = true;
    isTreeBalancedUtil(root, isBalanced);
    return isBalanced;
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

    cout<<isTreeBalanced(root)<<endl;

    vector<int> V = {1,3,5,6,9,12};
    Node_t *root_1 = minimalTree(V, 0, V.size()-1);
    postOrdTrav(root_1);
    cout<<isTreeBalanced(root_1)<<endl;
    return 0;
}
