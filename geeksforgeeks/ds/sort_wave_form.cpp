/*
Sort an array in wave form
Given an unsorted array of integers, sort the array into a wave like array. An array ‘arr[0..n-1]’ is sorted in wave form
if arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..
*/

#include <iostream>
#include <algorithm>

using namespace std;

// Sort array in ascending order then swap adjacent elements
// O(nlog n) if sorting used is an O(nlog n) sorting algorithm


void sortWaveForm1(int a[], int n)
{
    sort(a, a+n);

    // Swap adjacent elements
    for(int i = 0; i < n-1; i+=2)
        swap(a[i], a[i+1]);

}

/* O(n) solution --traverse the even elements
- if a[i-1] > a[i]
    swap element
- if a[i] < a[i+1]
    swap element
*/
void sortWaveForm2(int a[], int n)
{
    // Swap adjacent elements
    for(int i = 0; i < n-1; i+=2)
    {
        if(i > 0 && a[i-1] > a[i])
            swap(a[i-1], a[i]);

        if(a[i] < a[i+1])
            swap(a[i], a[i+1]);
    }
}


// Driver program to test above function
int main()
{
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortWaveForm1(arr, n);
    //sortWaveForm2(arr, n);
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    cout<<endl;
    return 0;
}
