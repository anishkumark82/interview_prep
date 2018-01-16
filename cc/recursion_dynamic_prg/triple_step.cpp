/*
8.1 Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3
steps at a time. Implement a method to count how many possible ways the child can run up the
stairs.
*/
#include <iostream>
#include <vector>
using namespace std;
// recursive solution
// O(3^n)
int recCountNoofWays(int n)
{
    if (n < 0) return 0;
    if (n == 0 || n == 1) return 1;

    return recCountNoofWays(n-1) + recCountNoofWays(n-2) + recCountNoofWays(n-3);
}

int countNoofWaysUtil(int n, vector<int> &memo)
{
    if (n < 0) return 0;
    if (n == 0 || n == 1) return 1;
    if(memo[n] == 0)
    {
        memo[n] = countNoofWaysUtil(n-1, memo) + countNoofWaysUtil(n-2, memo) + countNoofWaysUtil(n-3, memo);
    }
    return memo[n];
}
int countNoofWays(int n)
{
    vector<int> memo(n+1,0);
    return countNoofWaysUtil(n, memo);
}
int main()
{
    int n = 5;
    //cout<<"recCountNoofWays("<<n<<") : "<<recCountNoofWays(n)<<endl;
    cout<<"countNoofWays("<<n<<") : "<<countNoofWays(n)<<endl;
    return 0;
}
