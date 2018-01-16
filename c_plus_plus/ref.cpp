#include<iostream>
#include<cstring>
using namespace std;

void func(char * &array)
{
    strcpy(array, "Bye bye");
    return;
}
int main()
{
    char array[100] = "Hello world";
    char *x = array;
    func(x);
    cout<<array<<endl;
    return 0;
}
