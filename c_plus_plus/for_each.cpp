// for each
#include<iostream>
using namespace std;

int main()
{
    int arr[5]{0,10,20,30,40};

    for(auto &ele: arr)
    {
        cout<<ele<<" ";
    }
    return 0;
}
