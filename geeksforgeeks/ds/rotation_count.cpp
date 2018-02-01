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
#if 0
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
#endif

// 2, 3, 6, 12

/*
s = 0; e = 3
mid = 0 + 3 / 2 = 1
a[mid] = a[1] = 3
a[1] > a[2] => false
a[0] > a[1] => false
a[0] > a[1] => false
s = mid+1 = 2

s =2; e = 3
mid = 2 + 3 / 2 = 2

a[2] = 6 (a[mid])
a[1] >


*/
int findRotationCount(int *a, int start, int end)
{
    while(start < end)
    {
        int mid = (start + end) /2;
        // Find the pivot element
        if((mid+1 <= end) && (a[mid] > a[mid+1]))
            return mid+1;
        if(((mid-1) >= start) && (a[mid-1] > a[mid]))
            return mid; // Pivot + 1
        if(a[start] > a[mid]) // So pivot is to the left
        {
            end = mid - 1;
        }
        else // a[start] < a[mid], pivot to the right
        {
            start = mid + 1;
        }
    }
    // No rotation
    return 0;
}
// Driver code
int main()
{
    int arr[] = {15, 18, 2, 3, 6, 12};
    //int arr[] = {2, 3, 6, 12};

    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findRotationCount(arr, 0, n-1);
    return 0;
}
