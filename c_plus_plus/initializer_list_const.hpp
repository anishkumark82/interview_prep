#include<iostream>
using namespace std;
class Sample
{
    const int mMAX;

    public:
    static int x;
    //Sample(int max): mMAX(max)
    Sample(int max): mMAX{max} // uniform initializer list
    {
        // Const can be initialized only by initializer_list
    }
    void print();
};
