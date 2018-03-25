// unique pointer
#include<iostream>
#include<memory>
using namespace std;
// unique_ptr has exclusive ownership, light weight pointers
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



void test()
{
    unique_ptr<Dog> p1(new Dog("Smokey"));

    p1->bark();
    unique_ptr<Dog> p2(new Dog("Gunner"));
    p2->bark();

    p2 = move(p1);
    p2->bark();

    unique_ptr<Dog[]> p3_arr(new Dog[3]); // unigue pointers are adapted for arrays
}
int main()
{
    test();
    return 0;
}
