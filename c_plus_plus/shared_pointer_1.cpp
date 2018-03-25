// shared pointer 1

#include<iostream>
#include<memory>
using namespace std;
// Has shared ownership
class Dog
{
    string m_name;
public:
    Dog():m_name("nameless")
    {
        cout<<"Default "<<__func__<<endl;
    }

    Dog(string name):m_name(name)
    {
        cout<<__func__<<endl;
    }
    ~Dog()
    {
        cout<<m_name<<__func__<<endl;
    }
    void bark()
    {
        cout<<__func__<<" "<<m_name<<" Bark ... "<<endl;
    }
};

void f(shared_ptr<Dog> ptr)
{
    cout<<__func__<<endl;
    ptr->bark();
}
void foo()
{
    shared_ptr<Dog> p = make_shared<Dog>("Hero");
    p->bark();
    cout<<"Usage : "<<p.use_count()<<endl;
    {
        shared_ptr<Dog> p2 = p;
        p2->bark();
        cout<<"Usage : "<<p.use_count()<<endl;
        cout<<"Usage : "<<p2.use_count()<<endl;
    }
    cout<<"Usage : "<<p.use_count()<<endl;
    // Custom deleteor
    shared_ptr<Dog> p3(new Dog[3], [](Dog *p){cout<<"Custom deleter ..."<<endl; delete []p;});   // Needs custom deleteor or else when going out of scope p3 shall only delete  dog[0]
    shared_ptr<Dog> p4 = make_shared<Dog>("Smokey");
    f(p4);
    if(p4 == nullptr)
    {
        cout<<"deleted by f()"<<endl;
    }
}


int main()
{
    foo();
    return 0;
}
