#include<iostream>
// Learning to use templates
using namespace std;

// function template
template <typename T>
T square(T &x)
{
    return x * x;
}

// class templates

template <typename T>
class akVector
{
    T arr[1000];
    int size;
public:
    akVector()
    {
        size = 0;
    }
    void push(T x)
    {
        if(size < 1000)
        {
            arr[size] = x;
            size++;
        }
    }
    void print()
    {
        for(int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    ~akVector()
    {
        size = 0;
    }
    T getAt(int i)
    {
        return arr[i];
    }
    int getSize()
    {
        return size;
    }
    akVector<T> operator*(akVector &rhs2)
    {
        akVector<T> temp;
        for(int i = 0; i < getSize(); i++)
        {
            arr[i] *= rhs2.getAt(i);
            temp.push(arr[i]);
        }
        return temp;
    }

};

int main()
{
    cout<<square(5)<<endl;
    cout<<square(5.5)<<endl;

    akVector<int> intV;
    intV.push(10);
    intV.push(20);
    intV.push(30);
    intV.push(40);
    intV = square(intV);
    intV.print();


    return 0;
}
