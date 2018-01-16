#include<iostream>
using namespace std;

class Base
{
public:
    int a_public;
protected:
    int b_protected;
private:
    int c_private;

public:
    Base()
    {
        cout<<__func__<<endl;
        a_public = 5;
        b_protected = 10;
        c_private = 15;
    }
    ~Base()
    {
        cout<<__func__<<endl;
    }
    virtual int getA()
    {
        cout<<"Base::"<<__func__<<endl;
        return a_public;
    }
    virtual int getB()
    {
        cout<<"Base::"<<__func__<<endl;
        return b_protected;
    }
    virtual int getC()
    {
        cout<<"Base::"<<__func__<<endl;
        return c_private;
    }
};

class Derived_pub: public Base
{
public:
    Derived_pub()
    {
        cout<<__func__<<endl;
    }
    ~Derived_pub()
    {
        cout<<__func__<<endl;
    }

    int getA()
    {
        cout<<"Derived_pub::"<<__func__<<endl;
        return a_public;
    }
    int getB()
    {
        cout<<"Derived_pub::"<<__func__<<endl;
        return b_protected;
    }

    /*
    The below function does not work. We are trying to access a private member in Base using a function in derived class.
    Whose existence Derived_pub should not be made aware
    int getC()
    {
        cout<<"Derived_pub::"<<__func__<<endl;
        return c_private;
    }
    */

};

class Derived_prot: protected Base
{
public:
    Derived_prot()
    {
        cout<<__func__<<endl;
    }
    ~Derived_prot()
    {
        cout<<__func__<<endl;
    }
    int getA()
    {
        cout<<"Derived_prot::"<<__func__<<endl;
        return a_public;
    }
    int getB()
    {
        cout<<"Derived_prot::"<<__func__<<endl;
        return b_protected;
    }
    /*
    The below function does not work. We are trying to access a private member in Base using a function in derived class.
    Whose existence Derived_prot should not be made aware
    int getC()
    {
        cout<<"Derived_prot::"<<__func__<<endl;
        return c_private;
    }
    */


};

class Derived_priv: private Base
{
public:
    Derived_priv()
    {
        cout<<__func__<<endl;
    }
    ~Derived_priv()
    {
        cout<<__func__<<endl;
    }
    int getA()
    {
        cout<<"Derived_priv::"<<__func__<<endl;
        return a_public;
    }
    int getB()
    {
        cout<<"Derived_priv::"<<__func__<<endl;
        return b_protected;
    }

    /*
    The below function does not work. We are trying to access a private member in Base using a function in derived class.
    Whose existence Derived_priv should not be made aware
    int getC()
    {
        cout<<"Derived_priv::"<<__func__<<endl;
        return c_private;
    }
    */
};

int main()
{

    // To understand access specifiers in a class
    Base b;
    cout<<b.a_public<<endl;
    // Protected is like private and cannot be accessed directly but can be accessed by base class's and inherited classes member functions.
    //cout<<b.b_protected<<endl;
    cout<<b.getB()<<endl;
    // Private member can be accessed only by base class's member function
    //cout<<b.c_private<<endl;
    cout<<b.getC()<<endl;

    // ========= dpub inherits public members of base with public access. So a_public can be accessed directly by dpub.
    Derived_pub dpub;
    cout<<dpub.a_public<<endl;
    // Protected is like private and cannot be accessed directly but can be accessed by base class's and inherited classes member functions.
    //cout<<dpub.b_protected<<endl;
    cout<<dpub.getB()<<endl;
    // Private member can be accessed only by base class's member function
    //cout<<dpub.c_private<<endl;
    cout<<dpub.getC()<<endl; // Private classes member function

    // ========= dprot inherits public members of base with protected access. So a_public cannot be accessed directly by dprot. Can be only accessed via member functions
    Derived_prot dprot;
    //cout<<dprot.a_public<<endl;
    cout<<dprot.getA()<<endl;
    // Protected is like private and cannot be accessed directly but can be accessed by base class's and inherited classes member functions.
    //cout<<dprot.b_protected<<endl;
    cout<<dprot.getB()<<endl;
    // Private member can be accessed only by base class's member function
    //cout<<dprot.c_private<<endl;
    // Cannot access getC() of base since Base was inherited as private
    //cout<<dprot.getC()<<endl; // Private classes member function

    return 0;
}
