// Jump search n/m + m-1 comparisons
// ideal value of m = sqrt(n) -> O(sqrt(n))

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int jump_search(vector<int> arr, int key)
{
    int m = sqrt(arr.size() - 1);
    int count = 0;
    while ((arr[m*count] <  key) && (m*count < (arr.size()- 1)))
        count +=1;
    if(arr[m*count] == key)
        return m*count;
    for(int i = m*(count -1); i < m*count; i++)
        if(arr[i] == key)
            return i;
    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    cout<<"10 is in index :: "<< jump_search(arr, 10)<<endl;
    cout<<"5 is in index :: "<< jump_search(arr, 5)<<endl;
    cout<<"2 is in index :: "<< jump_search(arr, 2)<<endl;
    cout<<"100 is in index :: "<< jump_search(arr, 100)<<endl;
    cout<<"9 is in index :: "<< jump_search(arr, 9)<<endl;

    return 0;
}
