// overloading new and delete in a class
#include <iostream>
#include <cstdlib>
using namespace std;

class student
{
public:
    student()
    {
        cout<<__func__<<endl;
    }
    ~student()
    {
        cout<<__func__<<endl;
    }

    void *operator new(size_t size)
    {
        cout<<"student::"<<__func__<<endl;
        //void *ptr = ::new student();
         void *ptr = malloc(size);
        return ptr;
    }
    void operator delete(void *ptr)
    {
        cout<<"student::"<<__func__<<endl;
        //::delete ptr;
        free(ptr);
    }
};

int main()
{
    student *pStud = new student;
    delete pStud;
    return 0;
}
