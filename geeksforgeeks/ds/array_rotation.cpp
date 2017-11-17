
#include <stdio.h>
#include <iostream>
using namespace std;
/* Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements. */
/* Time complexity O(n*d) method */
/* Space complexity O[1] */
void rotateLeft(int *arr, int n)
{
    int temp = arr[0];
    for(int i = 1; i < n; i++)
        arr[i-1] = arr[i];
    arr[n-1] = temp;
}
void rotatebyD(int *arr, int n, int d)
{
    for(int i = 0; i < d; i++)
        rotateLeft(arr,n);
}

// a should be greater than b
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b,a%b);
}

// 1. find the gcd of n, d
// 2. divide the array gcd times. example array of 12 elements with d = 3; rotate each element in each set.
/*
Let arr[] be {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}

a)    Elements are first moved in first set – (See below diagram for this movement)

ArrayRotation

          arr[] after this step --> {4 2 3 7 5 6 10 8 9 1 11 12}

b)    Then in second set.
          arr[] after this step --> {4 5 3 7 8 6 10 11 9 1 2 12}

c)    Finally in third set.
          arr[] after this step --> {4 5 6 7 8 9 10 11 12 1 2 3}
          */
/* O(gcd(n,d) method */
void rotateUsingGCD(int *arr, int n, int d)
{
    for(int i = 0; i < gcd(n,d); i++)
    {
        cout<<"i = "<<i<<"gcd(n,d) = "<<gcd(n,d)<<endl;
        int temp = arr[i];
        int j = i;
        int k;
        while(1)
        {
            k = j + d;
            if(k >= n) /* rotate to the start */
                k = k - n;
            if (k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

/* Driver program to test above functions */
int main()
{
   int arr[] = {1, 2, 3, 4, 5, 6, 7};
   rotateUsingGCD(arr, 7, 2);
   cout<<"rotated array "<<endl;
   for(int i = 0; i < 7;i++)
       cout<<arr[i]<<" ";
   getchar();
   return 0;
}
