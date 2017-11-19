/*
Quickly find multiple left rotations of an array | Set 1
Given an array of size n and multiple values around which we need to left rotate the array.
How to quickly find multiple left rotations?
*/

/*
O(1) to find the elements after k rotations but O(n) for traversal
O(n) space complexity
*/
#include <iostream>
using namespace std;

void preprocess(int a[], int n, int temp[])
{
    for(int i = 0; i < n; i++)
        temp[i] = temp[i+n] = a[i];
}
void leftRotate(int *a, int n, int k, int *temp)
{
    int start = k % n;
    cout<<"Array after "<<k<<" rotations : ";
    for (int i = start; i < start + n; i++)
        cout<<temp[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int temp[2*n];
    preprocess(arr, n, temp);

    int k = 2;
    leftRotate(arr, n, k, temp);

    k = 3;
    leftRotate(arr, n, k, temp);

    k = 4;
    leftRotate(arr, n, k, temp);

    return 0;
}
