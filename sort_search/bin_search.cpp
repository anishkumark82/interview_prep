// Binary Search

// Can be done on a sorted Array in log(n) time

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binSearchUtil(const vector<int> &vec, int n, int start, int end)
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
            return binSearchUtil(vec, n, start, mid-1);
        }
        return binSearchUtil(vec,n, mid+1, end);
    }
    return -1;
}
/* {4,7,10,12,27,29,56,78,87}
      ^     ^
         ^
 Example n = 10
    start  = 0  end = 8  mid = 4 v[27] > 10
    start = 0, end = 3, mid = (0 + 3) /2 = 1 v[1]=7 < 10
    start = 1, end = 3, mid = 1+3 / 2 = 2 v[2]=10 == 10
*/
int binSearchUtilItr(const vector<int> &vec, int n, int start, int end)
{
    while(start <= end)
    {
        int mid = (start + end) / 2;
        if(vec[mid] == n)
        {
            return mid;
        }
        if(vec[mid] > n)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return -1;
}
int bin_search(vector<int> vec, int n)
{
    //return binSearchUtil(vec, n, 0, vec.size()-1);
    return binSearchUtilItr(vec, n, 0, vec.size()-1);
}
int main()
{
    vector<int> vec {4,7,10,12,27,29,56,78,87};
    cout<<"found 10 in location : "<<bin_search(vec,10)<<endl;
    cout<<"found 15 in location : "<<bin_search(vec,15)<<endl;
    cout<<"found  4 in location : "<<bin_search(vec,4)<<endl;
    cout<<"found  1 in location : "<<bin_search(vec,1)<<endl;
    cout<<"found 87 in location : "<<bin_search(vec,87)<<endl;
    cout<<"found 88 in location : "<<bin_search(vec,88)<<endl;
    return 0;
}
