/*
Maximum sum of i*arr[i] among all rotations of a given array
*/

// O(n) Solution
/*
Let us calculate initial value of i*arr[i] with no rotation
R0 = 0*arr[0] + 1*arr[1] +...+ (n-1)*arr[n-1]

After 1 rotation arr[n-1], becomes first element of array,
arr[0] becomes second element, arr[1] becomes third element
and so on.
R1 = 0*arr[n-1] + 1*arr[0] +...+ (n-1)*arr[n-2]

R1 - R0 = arr[0] + arr[1] + ... + arr[n-2] - (n-1)*arr[n-1]

After 2 rotations arr[n-2], becomes first element of array,
arr[n-1] becomes second element, arr[0] becomes third element
and so on.
R2 = 0*arr[n-2] + 1*arr[n-1] +...+ (n?1)*arr[n-3]

R2 - R1 = arr[0] + arr[1] + ... + arr[n-3] - (n-1)*arr[n-2] + arr[n-1]

If we take a closer look at above values, we can observe
below pattern

Rj - Rj-1 = arrSum - n * arr[n-j]

Where arrSum is sum of all array elements, i.e.,

arrSum = ∑ arr[i]
        i<=0<=n-1
*/

#include <iostream>

using namespace std;

int maxRotatedSum(int *a, int n)
{
    int maxSum = 0;
    int rPrev = 0;

    // Rj = Rj-1 + array_sum - n(a[n-j])

    //array_sum
    int array_sum = 0;
    for(int i = 0; i < n; i++)
        array_sum += a[i];

    // Find R0
    for(int i = 0; i < n; i++)
        maxSum += i * a[i];
    rPrev = maxSum;

    // find max of RJ (j = 1,2 ... n-1) from R0 sum
    for( int j = 1; j < n; j++)
    {
        int rj = rPrev + array_sum - (n * a[n-j]);
        if(rj > maxSum)
            maxSum = rj;
    }
    return maxSum;
}

int main(void)
{
    int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "\nMax sum is " << maxRotatedSum(arr, n);
    return 0;
}
