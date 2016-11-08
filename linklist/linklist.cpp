// Link list (not using std::list or std::queue)
// Basic operations
// - insert() - front - O(1)
// - insert() - rear - O(n)
// - insert_pos() -  O(n)
// - delete_pos() - O(n)

#include <iostream>

using namespace std;

typedef struct _node
{
    int data;
    struct _node *next;
}node;

// create a node
node *create_node(int &data)
{
    node *temp = new node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

bool isEmpty(node *head)
{
    return(head == NULL);
}

// Insert in the rear of the list
bool insert_rear(node **headptr, int &&data) // Builds only with C++11
{
    node *temp = create_node(data);
    bool status = (temp);

    if(status)
    {
        if(*headptr == NULL)
        {
            *headptr = temp;
        }
        else
        {
            node *temp1 = *headptr;
            while(temp1->next)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp;
        }
    }
    return status;
}

// insert in the front of the list
bool insert_front(node **headptr, int &&data) // Builds only with C++11
{
    node *temp = create_node(data);
    bool status = (temp);

    if(status)
    {
        temp->next = *headptr;
        *headptr = temp;
    }
    return status;
}
// insert at a given position
bool insert_pos(node **headptr, int &&data, int pos) // Builds only with C++11
{
    bool status = true;
    if(pos == 1)
    {
        node *temp = create_node(data);
        temp->next = *headptr;
        *headptr = temp;
    }
    else
    {
        node *temp1 = *headptr;
        int i;
        for(i = 1; ((i < pos-1) && (temp1->next != NULL)); i++)
        {
            temp1 = temp1->next;
        }
        if(i == pos - 1)
        {
            node *temp = create_node(data);
            status = (temp);
            temp->next = temp1->next;
            temp1->next = temp;
        }
        else
        {
            status = false;
        }
    }
    return status;
}

// delete a node at a given position
bool delete_pos(node **headptr, int pos)
{
    bool status = false;

    if(*headptr != NULL)
    {
        node *temp = *headptr;
        int i;
        for(i = 1; ((i < pos-1) && (temp->next != NULL)); i++)
        {
            temp = temp->next;
        }
        if(i == pos - 1)
        {
            node *temp1 = temp->next;
            if(temp1 != NULL)
            {
                temp->next = temp1->next;
                delete temp1;
                status = true;
            }
        }
    }
    return status;
}

// reverse the link list
void reverse_list(node **head_ptr)
{
    if(*head_ptr == NULL)
    {
        return;
    }
    node *current = *head_ptr, *previous = NULL, *next_node = NULL;
    while(current)
    {
        next_node = current->next;
        current->next = previous;
        previous = current;
        current = next_node;
    }
    *head_ptr = previous;
}

// Recursive utility function
void reverse_util(node **head_ptr, node *p)
{
    if(p->next == NULL)
    {
        *head_ptr = p;
        return;
    }
    reverse_util(head_ptr, p->next);
    p->next->next = p;
    p->next = NULL;
    return;
}

// reverse the link list
void reverse_list_recursive(node **head_ptr)
{
    if(*head_ptr == NULL)
    {
        return;
    }
    reverse_util(head_ptr, *head_ptr);
}

// Display contents of list
void display_list(node *head)
{
    cout<<endl;
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void display_list_recursive(node *head)
{
    if(head == NULL)
    {
        cout<<endl;
        return;
    }
    cout<<head->data<<" ";
    display_list_recursive(head->next);
    return;
}

int main()
{
    node *head = NULL;
    insert_pos(&head,4,1); // 4
    display_list(head);
    insert_pos(&head,5,2); // 4,5
    display_list(head);
    insert_pos(&head,10,1); // 10,4,5
    display_list_recursive(head);
    insert_pos(&head,20,10); // errpr
    display_list_recursive(head);
    insert_pos(&head,20,4); // 10, 4, 5, 20
    display_list_recursive(head);

    reverse_list(&head);

    display_list_recursive(head);
    delete_pos(&head,4); // 20,5,4
    display_list_recursive(head);
    delete_pos(&head,2); // 20,4
    display_list_recursive(head);
    insert_pos(&head,6, 2); // 20,6, 4
    display_list_recursive(head);
    delete_pos(&head,1); // 6, 4
    display_list(head);

    insert_pos(&head,8, 1); // 8, 6, 4
    display_list_recursive(head);
    insert_pos(&head,10, 2); // 8, 10, 6, 4
    display_list_recursive(head);

    insert_pos(&head,9, 4); // 8, 10, 6, 9, 4
    display_list_recursive(head);
    reverse_list_recursive(&head);
    display_list_recursive(head);

    return 0;
}
