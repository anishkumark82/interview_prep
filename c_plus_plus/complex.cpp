#include <iostream>
using namespace std;
class Complex
{
    int r;
    int i;

    public:
    Complex(int R = 0, int I = 0): r(R), i(I)
    {
    }
    ~Complex()
    {

    }
    Complex operator+(Complex &rhs)
    {
        return Complex( r + rhs.r, i + rhs.i);
    }
    void operator+=(Complex &rhs)
    {
         r += rhs.r; i += rhs.i;
    }
    void print()
    {
        cout<<r<<" + i"<<i<<endl;
    }
    Complex &operator++() // prefix
    {
        cout<<"operator++() : "<<endl;
        ++r; ++i;
        return (*this);
    }
    Complex operator++(int) //postfix
    {
        cout<<"operator++(int) : "<<endl;

        Complex temp(*this);
        r++; i++;
        return temp;
    }
    // Create a friend function to overload print data
    friend ostream& operator<<(ostream &o, const Complex &rhs);
};

class MyArray
{
    int arr[5]= {1,2,3,4,5};
public:
    MyArray()
    {

    }
    MyArray(const MyArray &rhs)
    {
        for(int i; i < 5; i++)
            arr[i] = rhs.arr[i];
    }
    ~MyArray()
    {

    }
    int& operator[](const int index)
    {
        return arr[index];
    }
    MyArray& operator++() //pre-increment
    {
        for(int i = 0; i < 5; i++)
            ++arr[i];
        return *this;
    }
    MyArray operator++(int) //post-increment
    {
        MyArray temp(*this);
        for(int i = 0; i < 5; i++)
            ++arr[i];
        return temp;
    }
    friend ostream& operator<<(ostream &o, const MyArray &rhs);
};

ostream& operator<<(ostream &o, const MyArray &rhs)
{
    o<<"MyArray : ( ";
    for(int i = 0; i < 5; i++)
        o<<rhs.arr[i]<<" ";
    o<<")";
    return o;
}
ostream& operator<<(ostream &o, const Complex &rhs)
{
    o<<"Complex("<<rhs.r<<" , "<<rhs.i<<")";
    return o;
}
int main()
{
    Complex C1(5,2);
    Complex C2(2,3);

    Complex C3 = C1+C2;
    C3.print();

    C3 += C2;
    C3.print();
    cout<<C3<<endl;
    cout<<"C3++ : "<<C3++<<endl;
    cout<<"++C3 : "<<++C3<<endl;

    MyArray A;

    cout<<A<<endl;
    cout<<A[1]<<endl;
    A[2] = 10;
    cout<<A<<endl;
    cout<<A++<<endl;
    cout<<++A<<endl;

    return 0;
}
