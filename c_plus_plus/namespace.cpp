#include <iostream>

using namespace std;

namespace sample
{
    int x = 10;
}
int main()
{
    int x = 20;

    cout<<x<<" "<<sample::x<<endl;
    return 0;
}
