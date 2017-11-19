/*
Find the Rotation Count in Rotated Sorted array
Consider an array of distinct numbers sorted in increasing order.
The array has been rotated (anti-clockwise) k number of times. Given such an array, find the value of k
*/

/* the algorithm involves finding the element after the pivot element. This can be done using linear or binary search */

/* Linear Search - O(n)
   Binary Search - O(logn)
*/

/* {15, 18, 2, 3, 6, 12} return location of 2 - index 2 */
#include <iostream>
using namespace std;
int findRotationCount(int *a, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start)/2;
        if ((mid < end) && (a[mid] > a[mid+1])) return mid + 1;
        if ((mid > start) && (a[mid-1] > a[mid])) return mid;
        if (a[start] >= a[mid])
            return findRotationCount(a, start, mid-1);
        return findRotationCount(a, mid+1, end);
    }
    else if (start == end)
    {
        return start;
    }
    return 0; /* No rotation done */
}

// Driver code
int main()
{
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findRotationCount(arr, 0, n-1);
    return 0;
}
