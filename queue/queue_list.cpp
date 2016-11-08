// Queue implementation using list (not using std::list or std::queue)
// Basic operations
// - push() - O(n)
// - pop() - O(1)
// - isEmpty() - O(1)

#include <iostream>

using namespace std;

template <typename T>
class MyQueue
{
private:
    typedef struct _node
    {
        T data;
        struct _node *next;
    }node;
    node *head;
    // create a node
    node *create_node(T &data)
    {
        node *temp = new node();
        temp->data = data;
        temp->next = NULL;
        return temp;
    }
public:
    MyQueue():
        head(nullptr)
    {}

    bool isEmpty()
    {
        return(head == NULL);
    }
    bool push(T &&data) // Builds only with C++11
    {
        node *temp = create_node(data);
        bool status = (temp);

        if(status)
        {
            if(head == NULL)
            {
                head = temp;
            }
            else
            {
                node *temp1 = head;
                while(temp1->next)
                {
                    temp1 = temp1->next;
                }
                temp1->next = temp;
            }
        }
        return status;
    }

    bool pop(T &data)
    {
        bool status = true;
        if(isEmpty())
        {
            status = false;
        }
        else
        {
            node *temp = head;
            data = temp->data;
            head = head->next;
            delete temp;
        }
        return status;
    }
    void display_q()
    {
        if(!isEmpty())
        {
            cout<<endl;
            node *temp = head;
            while(temp)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};
int main()
{
    MyQueue<int> q;
    int data;
    q.push(10);
    q.display_q();

    q.push(20);
    q.display_q();
    q.push(30);
    q.display_q();
    q.push(40);
    q.display_q();
    q.push(50);
    q.display_q();
    q.push(60);
    q.display_q();

    q.pop(data);
    q.display_q();

    q.pop(data);
    q.display_q();

    q.pop(data);
    q.display_q();

    q.pop(data);
    q.display_q();

    q.pop(data);
    q.display_q();
    return 0;
}
