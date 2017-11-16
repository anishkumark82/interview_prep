/*
Question
Find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted
Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e] such that sorting this subarray makes the whole array sorted.
Examples:
1) If the input array is [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60], your program should be able to find that the subarray lies between the indexes 3 and 8.
2) If the input array is [0, 1, 15, 25, 6, 7, 30, 40, 50], your program should be able to find that the subarray lies between the indexes 2 and 5.
*/



#include <stdio.h>
void findS_E(int arr[], int n)
{
    int s = 0;
    while((s < n-1) && (arr[s] < arr[s+1]))
        s++;
    if(s == n-1)
    {
        printf("Array is already sorted\n");
        return;
    }

    int e = n-1;
    while((e > 0) && (arr[e] > arr[e-1]))
        e--;

    // Check if s and e need to be extended to ensure the entire array is sorted
    // find min and max within s and e
    int min = arr[s];
    int max = arr[e];
    for (int i = s+1; i <= e; i++)
    {
        if (min > arr[i]) min = arr[i];
        if (max < arr[i]) max = arr[i];
    }
    // find an index which is greater than min from 1 to s-1
    for (int i = 0; i < s; i++)
        if (arr[i] > min)
        {
            s = i; break;
        }

    // find an index which is less than max from n-1 to e
    for (int i = n-1; i > e; i--)
        if (arr[i] < max)
        {
            e = i; break;
        }
    printf("Minimum Sub-array between %d,%d\n",s,e);
}
int main()
{
    int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    findS_E(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
