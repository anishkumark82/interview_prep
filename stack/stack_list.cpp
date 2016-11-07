// Stack array implementation using link list (not using std::list)
// Basic stack functionalities - LIFO
// Basic operations
// - push() - O(1)
// - pop() - O(1)
// - isEmpty() - O(1)
// - top() O(1)

#include <iostream>
using namespace std;

template <typename T>
class myStack
{
private:
    typedef struct _node
    {
        T data;
        struct _node *next;
    }node;
    node *head;

    // Function to create a node
    node *create_node(T &data)
    {
        node *temp = new node();
        temp->data = data;
        temp->next = NULL;
        return temp;
    }
public:
    /* Constructor */
    myStack():
        head(NULL)
    {}
    /* Destructor */
    ~myStack()
    {
        // Cleanup
        while(head)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool push(T &&data) // Using a reference to r-value -- need c++11
    {
        node *temp = create_node(data);
        bool status = (temp);
        if(status)
        {
            temp->next = head;
            head = temp;
        }
        return status;
    }
    bool pop()
    {
        bool status = !isEmpty();
        if(status)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
        return status;
    }
    bool stack_top(T &data)
    {
        bool status = (!isEmpty());
        if(status)
        {
           data = head->data;
        }
        return status;
    }
    bool isEmpty()
    {
        return (!head);
    }

    void display_stack()
    {
        node *temp = head;
        cout<<endl;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    myStack<int> s;

    s.push(10);
    s.display_stack();

    s.push(20);
    s.display_stack();
    s.push(30);
    s.display_stack();
    s.push(40);
    s.display_stack();
    s.push(50);
    s.display_stack();
    s.push(60);
    s.display_stack();

    s.pop();
    s.display_stack();

    s.pop();
    s.display_stack();

    s.pop();
    s.display_stack();

    s.pop();
    s.display_stack();

    s.pop();
    s.display_stack();
    return 0;
}
