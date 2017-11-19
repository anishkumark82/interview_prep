/* Given a sorted and rotated array, find if there is a pair with a given sum */

// 1. Find the pivot element 0(n) if linear search, binary search O(log n)
// then have l as lower index and h as higher index
// if l + h < s l++
// if l + h > s h--
// else l, h is the answer

#include <iostream>

using namespace std;

int findPivot(int *a, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start)/2;
        //cout<<"mid = "<<mid<<" start = "<<start<<" end = "<<end<<endl;
        if ((mid + 1 <= end) && (a[mid + 1] < a[mid]))
            return mid;
        if ((mid > start) && (a[mid - 1] > a[mid]))
            return mid - 1;
        if(a[start] >= a[mid])
            return findPivot(a, start, mid - 1);
        return findPivot(a, mid+1, end);
    }
    else if (start == end)
        return start;

    return -1;
}

bool findSuminArray(int *a, int n, int sum)
{
    int pivot = findPivot(a, 0, n-1);
    int l = 0, h = 0;
    bool found = false;
    cout<<"Pivot = "<<pivot<<endl;

    if (pivot == -1) // Array not rotated
    {
        l = 0;
        h = n-1;
    }
    else
    {
        l = (pivot + 1) % n;
        h = pivot;
    }

    while ((l!=h) && !found)
    {
        int s = a[l] + a[h];
        cout<< "s = "<<s<<" l = "<<l<<" h = "<<h<<" a[l] : "<<a[l]<<" a[h] : "<<a[h]<<endl;
        if (s == sum)
        {
            cout << "found the pair l : "<<l<<" and "<<h<<" sum = "<<sum<<endl;
            found = true;
        }

        else if (s < sum)
            l = (l + 1) % n;
        else
            h = (n + h - 1) % n;
    }
    return found;
}

/* Driver program to test above function */
int main()
{
    int arr[] = {11, 15, 6, 8, 9, 10};
    int sum = 16;
    int n = sizeof(arr)/sizeof(arr[0]);

    if (findSuminArray(arr, n, sum))
        cout << "Array has two elements with sum 16";
    else
        cout << "Array doesn't have two elements with sum 16 ";

    return 0;
}
