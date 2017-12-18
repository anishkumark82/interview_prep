/*
2.4 Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
before all nodes greater than or equal to x. lf x is contained within the list, the values of x only need
to be after the elements less than x (see below). The partition element x can appear anywhere in the
"right partition"; it does not need to appear between the left and right partitions.
*/
// Iterative approach
#include <iostream>

using namespace std;
// Create a list less than x and greater than x and concatenate the lists
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

void printList(Node_t *hd)
{
    while(hd)
    {
        cout<<hd->data<<" ";
        hd = hd->next;
    }
    cout<<endl;
}
void partition_list(Node_t **list1, int partition)
{
    Node_t *less_list_p = NULL;
    Node_t *less_list_hd_p = NULL;
    Node_t *greater_list_p = NULL;
    Node_t *greater_list_hd_p = NULL;
    Node_t *temp = *list1;

    while(temp)
    {
        if(temp->data < partition)
        {
            if(less_list_p == NULL)
            {
                less_list_p = temp;
                less_list_hd_p = less_list_p;
            }
            else
            {
                less_list_p->next = temp;
                less_list_p = temp;
            }
        }
        else if(greater_list_p == NULL)
        {
            greater_list_p = temp;
            greater_list_hd_p = greater_list_p;
        }
        else
        {
            greater_list_p->next = temp;
            greater_list_p = temp;
        }
        temp = temp->next;
    }
    if(less_list_hd_p)
    {
        less_list_p->next = greater_list_hd_p;
        *list1 = less_list_hd_p;
    }
    else
    {
        *list1 = greater_list_hd_p;
    }
    greater_list_p->next = NULL;
}

int main()
{
    Node_t *list_p = NULL;
    int p;
    cin>>p;
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
    cout<<"List before partition : "<<endl;
    printList(list_p);
    partition_list(&list_p, p);
    cout<<"List after partition : "<<endl;
    printList(list_p);

    return 0;
}
