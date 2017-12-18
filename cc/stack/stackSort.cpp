/*
3.5 Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can use
an additional temporary stack, but you may not copy the elements into any other data structure
(such as an array). The stack supports the following operations: push, pop, peek, and isEmpty.
*/

#include <iostream>
#include <stack>

using namespace std;

void sortStack(stack<int> &S)
{
    stack<int>tempStack;

    while(!S.empty())
    {
        if(tempStack.empty())
        {
            cout<<"tempStack is empty() : "<<S.top()<<endl;
            tempStack.push(S.top());
            S.pop();
        }
        else if(S.top() >= tempStack.top())
        {
            cout<<"S.top greater than tempStack.top() : S.top() : "<<S.top()<<" , tempStack.top() : "<<tempStack.top()<<endl;
            tempStack.push(S.top());
            S.pop();
        }
        else // S.top() > tempStack.top()
        {
            int temp = S.top();
            cout<<"S.top less than tempStack.top() : S.top() : "<<S.top()<<" , tempStack.top() : "<<tempStack.top()<<endl;
            S.pop();
            while(!tempStack.empty() && tempStack.top() > temp)
            {
                S.push(tempStack.top());
                tempStack.pop();
            }
            tempStack.push(temp);
        }

        cout<<"S.empty() : "<<S.empty()<<endl;
    }
    while(!tempStack.empty())
    {
        S.push(tempStack.top());
        tempStack.pop();
    }
}


int main()
{
    stack<int> S;
    S.push(8);
    S.push(2);
    S.push(5);
    S.push(10);
    S.push(8);
    S.push(7);
    sortStack(S);
    while(!S.empty())
    {
        cout<<S.top()<<" ";
        S.pop();
    }
    return 0;
}
