/*
2.2 Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.
*/

// Iterative approach
#include <iostream>

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

void printList(node *hd)
{
    while(hd)
    {
        cout<<hd->data<<" ";
        hd = hd->next;
    }
    cout<<endl;
}

node *kthNodefromlast(node *hd, int k)
{
    // Iterative approach
    // have 2 pointers at a gap of k nodes
    node *p1 = hd;
    node *p2 = hd;

    int i = 0;
    for(i = 0; (i < k) && (p1 != NULL); i++)
    {
        p1 = p1->next;
    }

    if((p1 == NULL) && (i != k))
    {
        cout<<"link list too short to find the kth element"<<endl;
        return NULL;
    }

    while(p1)
    {
        p2 = p2->next;
        p1 = p1->next;
    }
    return p2;
}
int main()
{
    node *list_p = NULL;
    int k;
    cin>>k;
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
    node *kthNode = kthNodefromlast(list_p, k);

    if(kthNode)
    {
        cout<<kthNode<<" : "<<kthNode->data<<endl;
    }
    return 0;
}
