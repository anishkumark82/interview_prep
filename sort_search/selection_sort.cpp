// Selection Sort
// O(n^2)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selection_sort(vector<int> &arr)
{
    for (int i = 0; i < arr.size()-1; i++)
    {
        int min_idx = i;
        for(int j = i+1; j < arr.size(); j++)
            if(arr[min_idx] > arr[j])
                min_idx = j;
        swap(arr[i], arr[min_idx]);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    selection_sort(arr);
    cout<<"sorted arr : ";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
