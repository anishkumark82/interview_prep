// Merge Sort
// O(nlog n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void merge(vector<int> &arr, int l, int m, int r)
{
    cout<<"l = " <<l<< " m = "<<m<<" r = "<<r<<endl;
    vector<int>L(m-l+1);
    vector<int>R(r - m);
    // Copy over the contents of the Left and right sub array
    for(int i = l; i <= m; i++)
    {
        L[i-l] = arr[i];
    }

    for(int i = m+1; i <= r; i++)
    {
        R[i-(m+1)] = arr[i];
    }

    int i = 0, j = 0, k = l;

    while(i < L.size() && j < R.size())
    {
        if(L[i] < R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while(i < L.size())
    {
        arr[k++] = L[i++];
    }
    while(j < R.size())
    {
        arr[k++] = R[j++];
    }

}


void mergeSort(vector<int> &arr, int l, int r)
{
    if(r - l < 2)
    {
        return;
    }

    int m = (l + r)/2;
    // Sort the left sub-array
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
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

