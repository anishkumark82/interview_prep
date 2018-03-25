#include "initializer_list_const.hpp"
using namespace std;

void Sample::print()
{
    cout<<"mMAX : "<<mMAX<<endl;
}
int Sample::x(0);
int main()
{
    Sample S(10);
    S.print();
    cout<<Sample::x<<endl;
    return 0;
}


