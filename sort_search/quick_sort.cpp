// Quick Sort
// O(nlog n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partitionArr(vector<int> &arr, int start, int end)
{
    int pivot = arr[end];
    int pIndex = start;
    for(int i = start; i < end; i++)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[end], arr[pIndex]);
    return pIndex;
}

void qSort(vector<int> &arr, int start, int end)
{
    if(start < end)
    {
        int pIndex = partitionArr(arr, start, end);
        qSort(arr, start, pIndex-1);
        qSort(arr, pIndex, end);
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

