#include <iostream>
#define MAX_QUEUE_SIZE 10
using namespace std;

class MyQueue
{
    int Q[MAX_QUEUE_SIZE] = {0};
    int front = -1;
    int rear = -1;
public:
    MyQueue()
    {
    }

    ~MyQueue()
    {
    }

    bool isQueueFull()
    {
        return (((rear + 1) % MAX_QUEUE_SIZE) == front);
    }

    bool isQueueEmpty()
    {
        return (front == -1 && rear == -1);
    }

    int Qfront()
    {
        return Q[front];
    }

    void Enqueue(int x)
    {
        if(!isQueueFull())
        {
            if(isQueueEmpty())
            {
               Q[++rear] = x;
               front = rear;
            }
            else
            {
                Q[rear] = x;
            }
            rear = (rear + 1) % MAX_QUEUE_SIZE;
        }
    }
    void Dequeue()
    {
        if(!isQueueEmpty())
        {
            front = (front + 1) % MAX_QUEUE_SIZE;
            if(front == rear)
            {
                front = -1; rear = -1;
            }
        }
    }
    void printQueue()
    {
        cout<<"front = "<<front<<endl;
        cout<<"Rear = "<<rear<<endl;
        int f = front;
        int r = rear;

        if(isQueueEmpty())
        {
            cout<<"Queue Empty"<<endl;
            return;
        }

        for(f = front; f != r;  f = (f + 1) % MAX_QUEUE_SIZE)
            cout<<Q[f]<<" ";
        cout<<endl;
    }
};

int main()
{
    MyQueue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Enqueue(60);
    Q.printQueue();
    Q.Enqueue(70);
    Q.Enqueue(80);
    Q.Enqueue(90);
    Q.printQueue();
    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();
    Q.printQueue();

    Q.Enqueue(5);
    Q.printQueue();
    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();
    Q.printQueue();
    Q.Enqueue(23);
    Q.printQueue();
    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();
    Q.printQueue();
    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();
    Q.printQueue();
    Q.Dequeue();
    Q.Dequeue();
    Q.printQueue();

    Q.Enqueue(12);
    Q.printQueue();

    return 0;
}
