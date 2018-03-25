#include <iostream>
using namespace std;
class X
{
    int a;
    int b;

public:
    X():
    b(this->a),
    a(10)
    {
        cout<<__func__<<endl;
    }
    ~X()
    {
        cout<<"a : "<<a<<" b : "<<b<<" "<<__func__<<endl;
    }
};
int main()
{
    X x;

    return 0;
}
