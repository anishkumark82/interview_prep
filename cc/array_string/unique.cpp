#include<iostream>
#include<algorithm>

// Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures?

// O(nlogn)
using namespace std;
bool isUnique(std::string s)
{
    sort(s.begin(), s.end()); // O(n log n)

    for(int i = 0; i < s.size()-1; i++)
    {
        if(s[i] == s[i+1])
            return false;
    }
    return true;
}

int main()
{
    std::string s;
    cin>>s;
    cout<<"isUnique() : " <<isUnique(s)<<endl;
    return 0;
}
