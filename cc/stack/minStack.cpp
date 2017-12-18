/*
3.2 Stack Min: How would you design a stack which, in addition to push and pop, has a function min
which returns the minimum element? Push, pop and min should all operate in 0(1) time.
*/
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

template <typename T>
class minStack
{
    stack<T>S;
    stack<T>minElements;

public:
    bool push(T data)
    {
        S.push(data);
        if (!minElements.empty())
        {
            if (minElements.top() >= data) // Or else if multiple elements are there then will lose the min element
            {
                minElements.push(data);
            }
        }
        else
        {
            minElements.push(data);
        }
    }
    void pop()
    {
        if (!S.empty())
        {
            if(S.top() == minElements.top())
            {
                minElements.pop();
            }
            S.pop();
        }
    }
    T top()
    {
        return S.top();
    }
    T min()
    {
        return minElements.top();
    }
    bool isEmpty()
    {
        return S.empty();
    }
};


int main()
{
    minStack<int> mS;
    mS.push(100);
    mS.push(95);
    mS.push(20);
    mS.push(80);
    mS.push(17);
    mS.push(12);
    mS.push(19);
    mS.push(8);
    mS.push(5);

    cout<<"min :: "<<mS.min()<<endl;
    cout<<"Popping ... "<<mS.top();
    mS.pop();
    cout<<"min :: "<<mS.min()<<endl;
    cout<<"Popping ... "<<mS.top();
    mS.pop();
    cout<<"min :: "<<mS.min()<<endl;
    cout<<"Popping ... "<<mS.top();
    mS.pop();
    cout<<"min :: "<<mS.min()<<endl;
    cout<<"Popping ... "<<mS.top();
    mS.pop();
    cout<<"min :: "<<mS.min()<<endl;
    cout<<"Popping ... "<<mS.top();
    mS.pop();
    cout<<"min :: "<<mS.min()<<endl;
    cout<<"Popping ... "<<mS.top();
    mS.pop();
    cout<<"min :: "<<mS.min()<<endl;

    return 0;
}
