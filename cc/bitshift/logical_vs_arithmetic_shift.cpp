#include <iostream>
using namespace std;

bool getbit(int a, int bit)
{
    return ((a & (1 << bit)) != 0);
}

void setbit(int &a, int bit)
{
    a |= (1 << bit);
}

void clearbit(int &a, int bit)
{
    a &= (~(1 << bit));
}

void clearMSBIbits(int &a, int i)
{
    a &= ((1 << i) - 1);
}

void clearLSBIbits(int &a, int i)
{
    a &= (-1 << (i + 1));
}

void updateBit(int &a, int bit, int v)
{
    a &= (~(1 << bit));
    a |= (v << bit);
}
int main()
{
    int x = -0x1234;

    // arithmetic shift
    for(int i=0; i < 40; i++)
    {
        x = x >> 1;
        cout<<hex<<x<<endl;
    }

    x = -0x1234;
    // Logical shift
    for(int i=0; i < 40; i++)
    {
        x = int((unsigned int)x >> 1);
        cout<<hex<<x<<endl;
    }

    // shift left 2 times
    cout<< (1 << 2)<<endl;
    return 0;
}
