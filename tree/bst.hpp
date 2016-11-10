#ifndef _BST_HPP_
#define _BST_HPP_

// Header file for the tree implementations
#define MAX(X,Y) \
    ((X) >= (Y)?(X):(Y))
// Node structure
typedef struct _node
{
    int data;
    struct _node *left;
    struct _node *right;
}node;

// function declaration to create a node
extern node *create_node(int data);

// function to insert a node to the bst
extern node *insert_node(node* root, int data);

// function to find the minimum in a bst
extern int findMin(node *root);

// function to find the maximum in a bst
extern int findMax(node *root);

// function to delete a node in bst
extern node *delete_node(node *root, int data);

// function to search a node in bst
extern node *search_node(node *root, int data);

// function to find ht of a bst/binary tree
extern int find_ht(node *root);

// function to do inorder traversal
extern void inorder_traversal(node *root);

// function to perform pre-order traversal
extern void preorder_traversal(node *root);

// function to perform post-order traversal
extern void postorder_traversal(node *root);

// function to check if a tree is a bst
extern bool isBST(node *root);

// function for Breadth first search
extern void bst_breadth_first_search(node *root);

// function to determine number of nodes in the binary tree
extern int bt_size(node *root);

// Iterative pre-order traversal
extern void preorder_iterative(node *root);

// Iterative post-order traversal
extern void postorder_iterative(node *root);

// Iterative in-order traversal
extern void inorder_iterative(node *root);
#endif // _BST_HPP_



