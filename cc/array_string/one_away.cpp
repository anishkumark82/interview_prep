/*
One Away: There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to check if they are
one edit (or zero edits) away.
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

// pale pal - 1 insert
// pale bale - 1 replace
// pal  pale - 1 remove

//O(n)
bool isOneInsertRemove(string str1, string str2)
{
    string first, second;

    if(abs(int(str1.size() - str2.size())) > 1)
    {
        //cout<<abs(int(str1.size() - str2.size()))<<endl;
        return false;
    }

    bool oneDiff = false;
    int n = 0;
    // loop through the smaller. There should be only one extra element in the bigger string
    if(str1.size() > str2.size())
    {
        first = str1;
        second = str2;
        n = str2.size();
    }
    else
    {
        first = str2;
        second = str1;
        n = str1.size();
        //cout<<"swap str1 and str2"<<endl;
    }

    for(int i = 0,j = 0; i < n; i++, j++)
    {
        if(first[j] != second[i])
        {
            i--; // compare i with the next element in first
            if(oneDiff)
                return false;
            oneDiff = true;
        }
    }
    return true;
}

bool isOneReplace(string str1, string str2)
{
    bool firstDiff = false;
    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] != str2[i] )
        {
            if(firstDiff)
                return false;
            firstDiff = true;
        }
    }
    return true;
}

bool isOneAway(string str1, string str2)
{
    if(str1.size() == str2.size())
        return isOneReplace(str1, str2);
    return isOneInsertRemove(str1, str2);

}

int main()
{
    string str1, str2;
    cin>>str1>>str2;
    cout<<isOneAway(str1, str2);
    return 0;
}
