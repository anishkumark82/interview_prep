// finding first or last occurrence of a number in a sorted array

// Use a modification binary search
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int find_occurrence(const vector<int> &vec, int n, bool first_occurence = true)
{
    int result = -1;
    int start = 0;
    int end = vec.size()-1;
    while(start<=end)
    {
        int mid = (start + end) /2;
        if(vec[mid] == n)
        {
            result = mid;
            // Want to check if there is an occurrence before mid
            if(first_occurence)
                end = mid - 1;
            else
                start = mid + 1;
        }
        else if (vec[mid] > n)
        {
            end = mid - 1;
        }
        else // vec[mid] < n
        {
            start = mid + 1;
        }
    }
    return result;
}

int occurrence_count(const vector<int> &v, int n)
{
    int last = find_occurrence(v, n, false);
    if(last == -1) return 0;
    int first = find_occurrence(v, n, true);
    return last - first + 1;
}
int main()
{
    vector<int> vec {4,7,10,10,10,10,56,78,78};
    cout<<"found 10 in location : "<<find_occurrence(vec,10)<<endl;
    cout<<"found 15 in location : "<<find_occurrence(vec,15)<<endl;
    cout<<"found  4 in location : "<<find_occurrence(vec,4)<<endl;
    cout<<"found  1 in location : "<<find_occurrence(vec,1)<<endl;
    cout<<"found 78 in location : "<<find_occurrence(vec,78)<<endl;
    cout<<"found 88 in location : "<<find_occurrence(vec,88)<<endl;
    cout<<"============================================================="<<endl;
    cout<<"found 10 in location : "<<find_occurrence(vec,10, false)<<endl;
    cout<<"found 15 in location : "<<find_occurrence(vec,15, false)<<endl;
    cout<<"found  4 in location : "<<find_occurrence(vec,4, false)<<endl;
    cout<<"found  1 in location : "<<find_occurrence(vec,1, false)<<endl;
    cout<<"found 78 in location : "<<find_occurrence(vec,78, false)<<endl;
    cout<<"found 88 in location : "<<find_occurrence(vec,88, false)<<endl;
    cout<<"============================================================="<<endl;
    cout<<"Count of 10 : " <<occurrence_count(vec, 10)<<endl;
    cout<<"Count of 15 : "<<occurrence_count(vec,15)<<endl;
    cout<<"Count of 4 : "<<occurrence_count(vec,4)<<endl;
    cout<<"Count of 1 : "<<occurrence_count(vec,1)<<endl;
    cout<<"Count of 78 : "<<occurrence_count(vec,78)<<endl;
    cout<<"Count of 88 : "<<occurrence_count(vec,88)<<endl;

    return 0;
}
