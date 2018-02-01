// Binary Search

// Can be done on a sorted Array in log(n) time

#include <iostream>
using namespace std;
int bin_search(const vector &vec, int n, int start = 0, int end = vec.size()-1)
{
    if(start <= end)
    {
        int mid = (start + end) / 2;
        if(vec[mid] == n)
        {
            return mid;
        }
        if(vec[mid] > n)
        {
            return bin_search(vec, n, start, mid-1);
        }
        return bin_search(vec,n, mid+1, end);
    }
    return -1;
}
int main()
{
    vector<int> vec {4,7,10,12,27,29,56,78,87};
    cout<<"found in location : "<<bin_search(vec,10);
    cout<<"found in location : "<<bin_search(vec,15);
    cout<<"found in location : "<<bin_search(vec,4);
    cout<<"found in location : "<<bin_search(vec,1);
    cout<<"found in location : "<<bin_search(vec,87);
    cout<<"found in location : "<<bin_search(vec,88);
    return 0;
}
