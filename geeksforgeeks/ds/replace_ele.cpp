/*
Replace every element with the greatest element on right side
*/

/*
Given an array of integers, replace every element with the next greatest element (greatest element on the right side) in the array. Since there is no element next to the last element, replace it with -1.
For example, if the array is {16, 17, 4, 3, 5, 2}, then it should be modified to {17, 5, 5, 5, 2, -1}.
*/
#include<iostream>
#include<vector>

using namespace std;
void replaceElement(vector<int> &arr)
{
    int max_value = arr.size()-1;
    arr[arr.size()-1] = -1;
    for(int i = arr.size()-2; i >= 0; i--)
    {
        int cur_val = arr[i];
        arr[i] = max_value;
        max_value = max(cur_val, max_value);
    }
}

void printArray(const vector<int> &arr)
{
    for(auto &ele : arr)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int>arr{16, 17, 4, 3, 5, 2};
    printArray(arr);
    replaceElement(arr);
    printArray(arr);
    return 0;
}
