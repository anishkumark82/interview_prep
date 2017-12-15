// Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.

// 2 strings can be permutations of each other if they have the same length and same character set.
// so if we sort the strings then it should be identical

using namespace std;
#include <iostream>
#include <algorithm>

bool isPermutation(string s1, string s2)
{
    sort(s1.begin(), s1.end()); // O(nlogn)
    sort(s2.begin(), s2.end()); // O(nlogn)

    return (s1 == s2);
}
int main()
{
    string s1, s2;
    cin>>s1;
    cin>>s2;
    cout<<"isPermutation() : "<< isPermutation(s1, s2);
    return 0;
}
