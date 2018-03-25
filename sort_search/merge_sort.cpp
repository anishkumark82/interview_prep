#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int l, int m, int r);
void mergeSort(vector<int> &arr, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

void merge(vector<int> &arr, int l, int m, int r)
{
    // create the left array and right array
    vector<int> L(m-l+1);
    vector<int> R(r-m);

    for(int i = 0; i < L.size(); i++)
    {
        L[i] = arr[l+i];
    }
    for(int i = 0; i < R.size(); i++)
    {
        R[i] = arr[m+1+i];
    }
    int i = 0; int j = 0; int k = l;
    while(i < L.size() && j < R.size())
    {
        if(L[i] <= R[j])
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
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    mergeSort(arr, 0, arr.size()-1);
    cout<<"sorted arr : ";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
