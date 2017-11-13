// Binary search. O(log n)

#include <iostream>
#include <vector>

using namespace std;
int binary_search(vector<int> arr, int start, int end, int key)
{
    if(start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return binary_search(arr, start, mid-1, key);
        return binary_search(arr, mid+1, end, key);
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    cout<<"10 is in index :: "<< binary_search(arr, 0, n-1, 10)<<endl;
    cout<<"5 is in index :: "<< binary_search(arr, 0, n-1, 5)<<endl;
    cout<<"2 is in index :: "<< binary_search(arr, 0, n-1, 2)<<endl;
    cout<<"100 is in index :: "<< binary_search(arr, 0, n-1, 100)<<endl;
    cout<<"9 is in index :: "<< binary_search(arr, 0, n-1, 9)<<endl;

    return 0;
}
