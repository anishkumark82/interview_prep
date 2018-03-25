#include <iostream>
using namespace std;
// Functor example
class myVector
{
    int arr[100];
    int idx;
    public:
    myVector()
    {
        idx = -1;
    }
    ~myVector()
    {
        idx = -1;
    }

    void push(int x)
    {
        arr[++idx] = x;
    }
    myVector &operator()(int a)
    {
        for(int i = 0; i <=idx; i++)
        {
            arr[i] += a;
        }
    }
    friend ostream& operator<<(ostream &o, const myVector &rhs);
};

ostream& operator<<(ostream &o, const myVector &rhs)
{
    o<<"myVector : ( ";
    for(int i = 0; i <=rhs.idx; i++)
    {
        o<<rhs.arr[i]<<" ";
    }
    o<<")";
}

int main()
{
    myVector X;

    X.push(1);
    X.push(2);
    X.push(3);
    X.push(4);
    X.push(5);

    cout<<X<<endl;
    X(4);
    cout<<X<<endl;
    return 0;
}
