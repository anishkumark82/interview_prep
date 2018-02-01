#include<iostream>
#include<cstring>
using namespace std;

void func(char* const &array)
{
    //strcpy(array, "Bye bye");
    cout<<array;
    return;
}
int main()
{
    char array[100] = "Hello world";
    //char *x = array;
    func(array);
    cout<<array<<endl;
    return 0;
}
