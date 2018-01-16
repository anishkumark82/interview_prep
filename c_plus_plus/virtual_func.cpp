// virtual functions

#include<iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout<<__func__<<endl;
    }
    virtual ~Base()
    {
        cout<<__func__<<endl;
    }
    void func1()
    {
        cout<<"Base:"<<__func__<<endl;
    }
    virtual void func2()
    {
        cout<<"Base:"<<__func__<<endl;
    }
};

class Derived: public Base
{
public:
    Derived()
    {
        cout<<__func__<<endl;
    }
    ~Derived()
    {
        cout<<__func__<<endl;
    }
    void func1()
    {
        cout<<"Derived:"<<__func__<<endl;
    }
    void func2()
    {
        cout<<"Derived:"<<__func__<<endl;
    }

};

int main()
{
    Base *bPtr = new Derived();
    bPtr->func1();
    bPtr->func2();
    delete bPtr;

    return 0;
}
