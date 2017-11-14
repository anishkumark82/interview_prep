// Insertion Sort
// O(n^2)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertion_sort(vector<int> &arr)
{
    for (int i = 1; i < arr.size()-1; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    insertion_sort(arr);
    cout<<"sorted arr : ";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

