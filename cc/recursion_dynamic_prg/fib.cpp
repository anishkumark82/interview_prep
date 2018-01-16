#include<iostream>
#include<vector>
using namespace std;
// O(2^n)
int fib_rec(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib_rec(n-1) + fib_rec(n-2);
}

int fib_monotized(int n, vector<int> &memo)
{
    if(n == 0) return 0;
    if(n == 1) return 1;

    if(memo[n] == 0)
    {
        memo[n] = fib_monotized(n-1,  memo) + fib_monotized(n-2, memo);
    }
    return memo[n];
}

int fib(int n)
{
    vector<int> memo(n+1, 0);
    return fib_monotized(n, memo);
}

int main()
{
    int n = 5;

    //cout<<"fib("<<n<<") : "<<fib_rec(n)<<endl;
    cout<<"fib("<<n<<") : "<<fib(n)<<endl;
    return 0;
}
