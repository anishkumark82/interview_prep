// creating a new and delete

#include <iostream>
#include <cstdlib>

using namespace std;

void *operator new(size_t size)
{
    cout<<__func__<<endl;
    void *ptr = malloc(size);
    return ptr;
}

void operator delete(void *ptr)
{
    cout<<__func__<<endl;
    free(ptr);
}

int main()
{
    int *p = new int;
    delete p;
    return 0;
}
