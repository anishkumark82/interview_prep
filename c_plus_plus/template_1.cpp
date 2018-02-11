#include<iostream>
using namespace std;

template <typename T>
T square(T x)
{
    return (x * x);
}
template <typename T>
class myVector
{
    T a[1000];
    int n = 0;
public:
    void push(T x)
    {
        a[n++] = x;
    }
    int getSize()
    {
        return n;
    }
    T getData(int i) const // kept it const so that the const types can call this function
    {
        return a[i];
    }
    void printVector() const
    {
        for(int i = 0; i < n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

    myVector<T> operator*(myVector<T> const &v2)
    {
        myVector<T> v3;
        for(int i = 0; i < getSize();i++)
        {
            v3.push(getData(i) * v2.getData(i));
        }
        return v3;

    }
};
int main()
{
    cout<<square(5)<<endl;
    cout<<square(5.5)<<endl;
    myVector<int> V;
    V.push(10);
    V.push(20);
    V.push(30);
    V.push(40);
    V.printVector();
    myVector<int>V2;
    V2 = square(V);
    V2.printVector();
    return 0;
}
