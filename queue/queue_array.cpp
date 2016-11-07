// Queue implementation using arrays (Circular Queue)
// Basic operations
// - push() - O(1)
// - pop() - O(1)
// - isEmpty() - O(1)
// - isFull() O(1)

#include <iostream>
#define MAX_QUEUE_SIZE 5

using namespace std;

template <typename T>
class MyQueue
{
private:
    int q_front; // Where data is read
    int q_rear; // Where data is inserted
    T q_array[MAX_QUEUE_SIZE];
public:
    MyQueue():
        q_front(-1),
        q_rear(-1)
    {}

    bool isFull()
    {
        return((!isEmpty()) && (((q_rear + 1) % MAX_QUEUE_SIZE) == q_front));
    }
    bool isEmpty()
    {
        return(q_front == -1 && q_rear == -1);
    }
    bool push(T data)
    {
        bool status = true;
        if(isFull())
        {
            status = false;
        }
        else if(isEmpty())
        {
            q_front = q_rear = 0;
        }
        else
        {
            q_rear = ((q_rear + 1) % MAX_QUEUE_SIZE);
        }
        if(status)
        {
           q_array[q_rear] = data;
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
            data = q_array[q_front];
            // Case where there is only one element in the queue
            if(q_front == q_rear)
            {
                q_front = q_rear = -1;
            }
            else
            {
                q_front = ((q_front + 1) % MAX_QUEUE_SIZE);
            }
        }
        return status;
    }
    void display_q()
    {
        if(!isEmpty())
        {
            cout<<endl;
            for(int i = q_front; i <= q_rear; i++)
            {
                cout<<q_array[i]<<" ";
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
