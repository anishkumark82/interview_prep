/*
2.8 Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the
beginning of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
as to make a loop in the linked list.
EXAMPLE
Input: A -> B -> C - > D -> E -> C [the same C as earlier)
Output: C
*/


// Iterative approach
#include <iostream>

using namespace std;
typedef struct _node
{
    int data;
    struct _node *next;
}Node_t;

Node_t *getNode(int data)
{
    Node_t *n = new Node_t();
    n->data = data;
    n->next = NULL;
    return n;
}
void insert(Node_t **h, int data)
{
    if(*h == NULL)
    {
        *h = getNode(data);
    }
    else
    {
        Node_t *temp = *h;
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = getNode(data);
    }
}

Node_t *searchNode(Node_t *hd_p, int data)
{
    while(hd_p)
    {
        if(hd_p->data == data)
        {
            return hd_p;
        }
        hd_p = hd_p->next;
    }
    return NULL;
}

Node_t *detectLoopNode(Node_t *hd_p)
{
    // Detect loop
    Node_t *p1 = hd_p;
    Node_t *p2 = hd_p;

    do
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }while(p2 && p1 != p2);

    cout<<"loop detected at "<<p1<<" : "<<p1->data;
    if(p2 == NULL)
    {
        cout<<"No loop...."<<endl;
        return NULL;
    }

    // Now using the node where the p1 and p2 met backtrack to the start of the loop
    p1 = hd_p;
    Node_t *loopDetectedNode = p2;
    while(1)
    {
        p2 = loopDetectedNode->next;
        while(p2->next != loopDetectedNode && p2->next != p1)
        {
            p2 = p2->next;
        }
        if(p2->next == p1)
        {
            return p1;
        }
        p1 = p1->next;
    }
}
int main()
{
    Node_t *list_p = NULL;

    insert(&list_p, 1);
    insert(&list_p, 2);
    insert(&list_p, 3);
    insert(&list_p, 4);
    insert(&list_p, 5);
    insert(&list_p, 6);
    insert(&list_p, 7);
    insert(&list_p, 8);
    insert(&list_p, 9);
    insert(&list_p, 10);

    Node_t *loopNode = searchNode(list_p, 5);
    cout<<"Address of 5 :"<<loopNode<<endl;
    Node_t *temp = list_p;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = loopNode;

    cout<<"Going to detec the loop"<<endl;
    Node_t *lNode_p = detectLoopNode(list_p);
    if(lNode_p)
    {
        cout<<"Loop Node :: "<<lNode_p<<" : "<<lNode_p->data;
    }

    return 0;
}
