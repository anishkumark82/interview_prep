// Quick Sort
// O(nlog n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partitionQ(vector<int>&arr, int start, int end)
{
    int pIndex = start;
    int pivot = end;

    for(int i = start; i < end; i++)
    {
        if(arr[i] <= arr[pivot])
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[pivot]);
    return pIndex;
}

void qSort(vector<int>&arr, int start, int end)
{
    if(start < end)
    {
        int p_idx = partitionQ(arr, start, end);
        qSort(arr, start, p_idx-1);
        qSort(arr, p_idx+1, end);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    qSort(arr, 0, n - 1);
    cout<<"sorted arr : ";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

