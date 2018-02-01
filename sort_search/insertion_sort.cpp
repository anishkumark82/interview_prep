// Insertion Sort
// O(n^2)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertion_sort(vector<int> &arr)
{
    for(int i = 1; i < arr.size(); i++)
    {
        int value = arr[i]; // current value to be inserted in the correct location
        int hole = i; // identifies the final location of value

        while(hole > 0 && arr[hole - 1] > value)
        {
            arr[hole] = arr[hole - 1]; // move elements to the right until the slot for the new index is reached
            hole--;
        }
        arr[hole] = value; // insert the node in the right location
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

