/*
Search an element in a sorted and rotated array
An element in a sorted array can be found in O(log n) time via binary search.
But suppose we rotate an ascending order sorted array at some pivot unknown to you beforehand.
So for instance, 1 2 3 4 5 might become 3 4 5 1 2. Devise a way to find an element in the rotated array in O(log n) time.
*/
#include <iostream>
using namespace std;

int binary_search(int *a, int start, int end, int key)
{
    if(start <= end)
    {
        int mid = start + (end - start)/2;
        if (key == a[mid])
            return mid;
        if (key > a[mid])
            return binary_search(a, mid+1, end, key);
        return binary_search(a, start, mid - 1, key);
    }
    return -1;
}
/* 3 4 5 1 2 pivot is the index of 5 (index ->2) */
int findPivot(int *a, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start)/2;
        if ((mid <= end) && (a[mid] > a[mid+1]))
            return mid;
        else if ((mid > start) && (a[mid] < a[mid-1]))
            return mid-1;
        if (a[start] >= a[mid])
            return findPivot(a, start, mid-1);
        return findPivot(a, mid+1, end);
    }
    else if(start == end)
        return start;
    return -1;
}

int pivotedBinarySearch(int *a, int n, int key)
{
    int pivot = findPivot(a, 0, n-1);
    cout<<"pivot = "<<pivot<<endl;
    if(pivot == -1)
        return binary_search(a, 0, n-1, key);
    if(a[0] <= key)
        return binary_search(a, 0, pivot-1, key);
    return binary_search(a, pivot+1, n-1, key);
}

/* Driver program to check above functions */
int main()
{
   // Let us search 3 in below array
   int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
   int n = sizeof(arr1)/sizeof(arr1[0]);
   int key = 3;
   cout<<"Index: "<< pivotedBinarySearch(arr1, n, key)<<endl;
   return 0;
}
