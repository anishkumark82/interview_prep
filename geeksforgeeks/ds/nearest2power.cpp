#include <iostream>
#include <cmath>
using namespace std;


int findNearestPowerOfTwo(int n)
{
    // Power of 2 <= number
    // 10 => 8 1010 => 1000
    if(n == 0) return 0;

    int count = -1;
    while(n)
    {
        count++;
        n >>= 1;
    }
    return pow(2,count);
}
int main()
{

    cout<<"findNearestPowerOfTwo(10) : "<<findNearestPowerOfTwo(10)<<endl;
    cout<<"findNearestPowerOfTwo(2) : "<<findNearestPowerOfTwo(2)<<endl;
    cout<<"findNearestPowerOfTwo(1) : "<<findNearestPowerOfTwo(1)<<endl;
    cout<<"findNearestPowerOfTwo(100) : "<<findNearestPowerOfTwo(100)<<endl;
    cout<<"findNearestPowerOfTwo(1000) : "<<findNearestPowerOfTwo(1000)<<endl;

    return 0;
}
