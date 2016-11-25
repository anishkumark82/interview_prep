// Binary search tree implementation

#include <iostream>
#include <stdio.h>
#include <limits>
#include "bst.hpp"
using namespace std;

// utility function to create a node
node *create_node(int data)
{
    node *temp = new node();
    if(temp)
    {
        temp->data = data;
        temp->left = temp->right = NULL;
    }
    return temp;
}

int main()
{
    node *root = NULL;
    node *search_data = NULL;
    root = insert_node(root, 100);
    root = insert_node(root, 80);
    root = insert_node(root, 90);
    root = insert_node(root, 120);
    root = insert_node(root, 110);
    root = insert_node(root, 70);
    root = insert_node(root, 140);
    root = insert_node(root, 130);
    root = insert_node(root, 115);

    search_data = search_node(root, 140);
    printf("Search_data : %p %d\n",search_data, search_data->data);
    search_data = search_node(root, 150);
    printf("Search_data : %p 150\n",search_data);

    printf("findMin() : %d\n",findMin(root));
    printf("findMax() : %d\n",findMax(root));

    printf("findtreeht() : %d\n",find_ht(root));

    //std::cout << "breadth first search\n";
    bst_breadth_first_search(root);

    std::cout << "\nDepth first search\n";
    std::cout << "Pre-order\n";
    preorder_traversal(root);
    std::cout << "\nIn-order\n";
    inorder_traversal(root);
    std::cout << "\nPost-order\n";
    postorder_traversal(root);

    printf("\nisBST() : %s\n",(isBST(root))?"True":"False");

    //printf("\ndetermine_if_bst() : %s\n",(determine_if_bst(root))?"True":"False");

    cout<<"Number of nodes in binary tree :: "<<bt_size(root)<<endl;

    cout << "\nPre-order iterative traversal\n";
    preorder_iterative(root);

    cout << "\nPost-order iterative traversal\n";
    postorder_iterative(root);

    cout << "\ninorder-order iterative traversal\n";
    inorder_iterative(root);

    cout<<"\nPrint nodes at each level using 2 queues"<<endl;
    bt_level_print_1(root);

    cout<<"\nPrint nodes at each level using 1 queue and delimiter"<<endl;
    bt_level_print_2(root);

    cout<<"\nReverse level order traversing"<<endl;
    bst_reverse_breadth_first_search(root);

    cout<<"\nlevel order spiral traversing "<<endl;
    bt_level_spiral_1(root);

    // Find common ancestor
    cout<<"Common ancestor for 80, 120 :: "<<bstFindCommonAncestor(root, 80, 120)<<endl;
    cout<<"Common ancestor for 70, 80 :: "<<bstFindCommonAncestor(root, 70, 80)<<endl;
    cout<<"Common ancestor for 70, 90 :: "<<bstFindCommonAncestor(root, 70, 90)<<endl;
    cout<<"Common ancestor for 115, 130 :: "<<bstFindCommonAncestor(root, 115, 130)<<endl;
    cout<<"Common ancestor for 110, 130 :: "<<bstFindCommonAncestor(root, 110, 130)<<endl;
    cout<<"Common ancestor for 120, 140 :: "<<bstFindCommonAncestor(root, 120, 140)<<endl;

    cout<<"Post order traversal using one stack "<<endl;
    postorder_iterative_2(root);
    return 0;
}
