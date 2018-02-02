// Heap Sort algorithm

// Sorting in O(N log N)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
inline int parentIdx(const vector<int> &arr, int cur)
{
    if(cur == 0)
    {
        return -1;
    }
    return (cur - 1) /2;
}

inline int leftChildIdx(const vector<int> &arr, int cur)
{
    return (2 * cur) + 1;
}


inline int rightChildIdx(const vector<int> &arr, int cur)
{
    return (2 * cur) + 2;
}

inline bool isLeaf(const vector<int> &arr, int cur)
{
    return (cur >= arr.size()/2);
}
// Insert function if the arr is already passed -- Can simplify if the array itself is created as a heap
void bubbleDown(vector<int> &arr, int cur, int end)
{
    // bubble down from current node
    while(cur <= end && !isLeaf(arr, cur))
    {
        int l = leftChildIdx(arr, cur);
        int r = rightChildIdx(arr, cur);
        int largest = cur;
        if((l <= end) && (arr[largest] < arr[l]))
            largest = l;
        if((r <= end) && (arr[largest] < arr[r]))
            largest = r;
        if(largest != cur)
        {
            swap(arr[cur], arr[largest]);
            cur = largest;
        }
        else
        {
            break;
        }
    }
}

void bubbleUp(vector<int> &arr, int cur)
{
    while(cur != 0)
    {
        int parIdx = parentIdx(arr, cur); // This call shall not fail since current is never 0
        if(arr[cur] > arr[parIdx])
        {
            swap(arr[cur], arr[parIdx]);
            cur = parIdx;
        }
        else
        {
            break;
        }
    }
}
void insertToHeap(vector<int> &arr, int node)
{
    arr.push_back(node);
    // bubble up
    bubbleUp(arr, arr.size()-1);
}
// 87 12 90 34 95

void heapifyArray(vector<int> &arr)
{
    // Start with non-leaf nodes -- In a heap last n/2 nodes will be leaf nodes
    for(int i = arr.size()/2 - 1; i>=0; i--)
    {
        bubbleDown(arr, i, arr.size()-1);
    }
    cout<<"Bubble down done"<<endl;
}

void  maxHeapify(vector<int> &arr)
{
    for(int i = arr.size()-1; i>0; i--)
    {
        swap(arr[0], arr[i]);
        bubbleDown(arr, 0, i-1);
    }
}

void heapSort(vector<int> &arr)
{
    heapifyArray(arr);
    maxHeapify(arr);
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
