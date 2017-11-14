// Merge Sort
// O(nlog n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeArr(vector<int>&arr, int l, int m, int r)
{
    int nL = m - l + 1;
    int nR = r - m;

    vector<int>L(nL);
    vector<int>R(nR);
    // Copy over L & R from arr
    for(int i = 0; i < nL; i++)
        L[i] = arr[l+i];
    for(int j = 0; j < nR; j++)
        R[j] = arr[m+1+j];

    int i = 0,j = 0,k = l;

    while(i < nL && j < nR)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            cout<<" arr["<<k<<"]"<<arr[k];
            k++; i++;
        }
        else
        {
            arr[k] = R[j];
            cout<<" arr["<<k<<"]"<<arr[k];
            k++; j++;
        }
    }
    while(i < nL)
    {
        arr[k] = L[i];
        cout<<" arr["<<k<<"]"<<arr[k];
        k++; i++;
     }
    while(j < nR)
    {
        arr[k] = R[j];
        cout<<" arr["<<k<<"]"<<arr[k];
        k++; j++;
    }
    cout<<endl;
}

void mergeSort(vector<int>&arr, int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        mergeArr(arr, l, m, r);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    mergeSort(arr, 0, n - 1);
    cout<<"sorted arr : ";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

