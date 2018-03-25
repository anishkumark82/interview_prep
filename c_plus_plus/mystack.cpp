#include<iostream>
using namespace std;
#define MAX_STACK_SIZE  10
class myStack
{
    int arr[MAX_STACK_SIZE];
    int top;

    public:
    myStack()
    {
        top = -1;
    }
    ~myStack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return (top == -1);
    }
    bool isFull()
    {
        return (top == MAX_STACK_SIZE-1);
    }
    void push(int x)
    {
        if(!isFull())
        {
            arr[++top] = x;
        }
    }

    void pop()
    {
        top--;
    }

    int stackTop()
    {
        return arr[top];
    }

    void print()
    {
        if(top == -1)
            cout<<"STACK EMPTY"<<endl;
        else
        {
            for(int i = 0; i <= top; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    myStack stack;

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();
    return 0;
}
