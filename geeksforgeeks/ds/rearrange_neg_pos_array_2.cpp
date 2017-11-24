/*
Rearrange positive and negative numbers with constant extra space
Given an array of positive and negative numbers, arrange them such that all negative integers appear before all the positive integers in the array without using any additional data structure like hash table, arrays, etc.
The order of appearance should be maintained.
*/

//O(n) solution
// Perform partition on zero

#include <iostream>
using namespace std;

void rearrange(int a[], int n)
{
    int pIndex = 0;
    for(int j = 0; j < n;j++)
    {
        if(a[j]< 0)
        {
            swap(a[j], a[pIndex]);
            pIndex++;
        }
    }
}
// Modified merge sort. To ensure the sorting is in place and only rearranges the negative numbers
// When merging always merge in the negative numbers first
void modifedMerge(int a[], int l, int m, int r)
{
    //cout<<"modifedMerge: l = "<<l<<" m = "<<m<<" r = "<<r<<endl;
    int nL = m-l+1;
    int nR = r - m;
    int L[nL]; int R[nR];

    for (int i = 0; i < nL; i++)
        L[i] = a[l+i];

    for (int i = 0; i < nR; i++)
        R[i] = a[m+1+i];

    int i=0, j=0, k = l;
    while(i < nL && (L[i] < 0))
        a[k++] = L[i++];
    while(j < nR && (R[j] < 0))
        a[k++] = R[j++];

    // Merge in positive numbers
    while(i < nL)
        a[k++] = L[i++];
    while(j < nR)
        a[k++] = R[j++];
    cout<<"End modifedMerge()"<<endl;

}

void rearrangeInPlace(int a[], int start, int end)
{
   cout<<"rearrangeInPlace: start = "<<start<<" end = "<<end<<endl;

    if(start < end)
    {
        int mid = start + (end - start)/2;
        rearrangeInPlace(a, start, mid);
        rearrangeInPlace(a, mid+1, end);
        modifedMerge(a, start, mid, end);
    }

}


/* Function to print an array */
void printArray(int A[], int size)
{
    for(int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

/* Driver program to test above functions */
int main()
{
    int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    //rearrange(arr, arr_size);
    cout<<"Calling rearrangeInPlace()"<<endl;
    rearrangeInPlace(arr, 0, arr_size-1);
    cout<<"Calling printArray()"<<endl;

    printArray(arr, arr_size);

    return 0;
}
