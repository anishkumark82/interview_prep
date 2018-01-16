// C++ Inheritance

#include <iostream>
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
};

class Derived : public Base
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
};

int main()
{
    Base *bptr = new Derived();
    //Derived d;
    delete bptr;

    cout<<"-----------------"<<endl;
    Derived *Dptr = new Derived();
    delete Dptr;
    return 0;
}
