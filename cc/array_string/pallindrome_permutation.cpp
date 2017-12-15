/*
Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
A palindrome is a word or phrase that is the same forwards and backwards. A permutation
is a rea rrangement of letters. The palindrome does not need to be limited to just dictionary words.
EXAMPLE
Input: Tact Coa
Output: True (permutations: "taco cat". "atco cta". etc.)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool checkifOnlyOneOrLessOdd(vector<int>char_ct)
{
    int odd_count = 0;
    for(int i = 0; i < char_ct.size(); i++)
    {
        if(char_ct[i] % 2 != 0)
            odd_count++;
        if(odd_count > 1)
            return false;
    }
    return (odd_count <= 1);
}
bool isPallindromePermutation(string s)
{
    vector<int>ch_count(128, 0);

    for(int i = 0; i < s.size(); i++)
    {
        ch_count[s[i]]++;
    }
    // one or less characters should have odd number of characters
    return(checkifOnlyOneOrLessOdd(ch_count));
}

int main()
{
    string str;
    cin>>str;
    cout<<"isPallindromePermutation() : "<<isPallindromePermutation(str)<<endl;
    return 0;
}
