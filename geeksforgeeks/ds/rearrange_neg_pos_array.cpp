/*
Rearrange positive and negative numbers in O(n) time and O(1) extra space
An array contains both positive and negative numbers in random order. Rearrange the array elements so that positive and negative numbers are placed alternatively. Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.

For example, if the input array is [-1, 2, -3, 4, 5, 6, -7, 8, 9], then the output should be [9, -7, 8, -3, 5, -1, 2, 4, 6]

The solution is to first separate positive and negative numbers using partition process of QuickSort. In the partition process, consider 0 as value of pivot element so that all negative numbers are placed before positive numbers. Once negative and positive numbers are separated, we start from the first negative number and first positive number, and swap every alternate negative number with next positive number.
*/

// Perform partition step similar to partion in qSort

#include <iostream>
#include <algorithm>
using namespace std;

void arrangePosNeg(int a[], int n)
{
    // Perform partition with zero - so that all numbers less than zero are on the left and all numbers greater than zero are to the right

    int pIndex = 0;
    for(int j = 0; j < n; j++)
        if(a[j] < 0)
        {
            swap(a[j], a[pIndex]);
            pIndex++;
        }

    // shuffle the positive and negative numbers
    int neg = 0;
    int pos = pIndex;

    // increment neg by 2 and pos by 1 so that positive numbers and negative numbers alternate
    while(pos < n && neg < pos && a[neg] < 0)
    {
        swap(a[neg], a[pos]);
        pos++;
        neg += 2;
    }
}
// A utility function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

// Driver program to test above functions
int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    arrangePosNeg(arr, n);
    printArray(arr, n);
    return 0;
}
