// Heap Sort implementation (Ascending order using min heap)
// O(n log n)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// methods
int left_child(int i)
{
    return (2 * i + 1);
}

int right_child(int i)
{
    return (2 * i + 2);
}

void maxHeapify(vector<int>&a, int n, int i)
{
    int large = i;
    int l = left_child(i);
    int r = right_child(i);

    if ((l < n) && (a[l] > a[i]))
        large = l;

    if ((r < n) && (a[r] > a[large]))
        large = r;

    if (large != i)
    {
        // swap the nodes
        swap(a[i], a[large]);
        // bubble down
        maxHeapify(a, n, large);
    }
}

void heapSort(vector<int>&a)
{
    // Bubble up the array
    for (int i = (a.size() - 1)/2; i >= 0; i--)
        maxHeapify(a, a.size(), i);

    // Extract max and re-heapify
    for (int i = a.size()-1; i >=0 ; i--)
    {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}


int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    heapSort(arr);
    cout<<"sorted arr : ";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
