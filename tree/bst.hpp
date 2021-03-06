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

// Print nodes in each level using 2 queues
extern void bt_level_print_1(node *root);

// Print nodes in each level using 1 queue and delimiter
extern void bt_level_print_2(node *root);

// Reverse level order traversing
extern void bst_reverse_breadth_first_search(node *root);

// Spiral level order traversing
extern void bt_level_spiral_1(node *root);

// Find common ancestor
extern int bstFindCommonAncestor(node *root, int data1, int data2);

// Post order traversal using one stack
extern void postorder_iterative_2(node *root);
#endif // _BST_HPP_



