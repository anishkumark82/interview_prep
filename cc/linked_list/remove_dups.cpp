/*
Remove Dups: Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
//O(n) solution
//Space complexity O(n)

// O(n2) solution is there where we check for each element in the list with remaining elements in the list
using namespace std;

typedef struct _node
{
    int data;
    struct _node *next;
}node;

node *getNode(int data)
{
    node *n = new node();
    n->data = data;
    n->next = NULL;
    return n;
}
void insert(node **h, int data)
{
    if(*h == NULL)
    {
        *h = getNode(data);
    }
    else
    {
        node *temp = *h;
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = getNode(data);
    }
}

void remove_dups(node **hd)
{
    unordered_set<int> node_set;
    node_set.insert((*hd)->data);
    node *temp = (*hd)->next;
    node *prev = *hd;
    while(temp)
    {
        pair<unordered_set<int>::iterator, bool> ret = node_set.insert(temp->data);
        if(!ret.second)
        {
            // Duplicate node - delete the current node
            node *temp2 = temp;
            temp = temp->next;
            prev->next = temp; // still prev node continues to be the previous node
            delete temp2;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
}

void printList(node *hd)
{
    while(hd)
    {
        cout<<hd->data<<" ";
        hd = hd->next;
    }
    cout<<endl;

}
int main()
{
    node *list_p = NULL;
    insert(&list_p, 5);
    insert(&list_p, 1);
    insert(&list_p, 10);
    insert(&list_p, 5);
    insert(&list_p, 7);
    insert(&list_p, 10);
    insert(&list_p, 2);
    insert(&list_p, 3);
    insert(&list_p, 8);
    insert(&list_p, 15);
    cout<<"List before duplicate deletion : "<<endl;
    printList(list_p);
    remove_dups(&list_p);
    cout<<"List after duplicate deletion : "<<endl;
    printList(list_p);

    return 0;
}
