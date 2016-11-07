// Stack array implementation
// Basic stack functionalities - LIFO
// Basic operations
// - push() - O(1)
// - pop() - O(1)
// - isEmpty() - O(1)
// - top() O(1)

// Time complexity for each operations
#include <iostream>
#define MAX_STACK_SIZE 5
using namespace std;


template <typename T>
class myStack
{
private:
    int top;
    T stack_arr[MAX_STACK_SIZE];
public:
    myStack():
        top(-1)
    {}
    bool push(T data)
    {
        bool status = true;
        if(!isFull())
        {
            stack_arr[++top] = data;
        }
        else
        {
            status = false;
        }
        return status;
    }
    bool pop()
    {
        bool status = true;
        if(!isEmpty())
        {
            top--;
        }
        else
        {
            status = false;
        }
        return status;
    }
    bool stack_top(T &data)
    {
        bool status = true;
        if(!isEmpty())
        {
           data = stack_arr[top];
        }
        else
        {
            status = false;
        }
        return status;
    }
    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top >= MAX_STACK_SIZE-1);
    }
    void display_stack()
    {
        cout<<endl;
        for(int i = 0; i <= top; i++)
        {
            cout<<stack_arr[i]<<" ";
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
