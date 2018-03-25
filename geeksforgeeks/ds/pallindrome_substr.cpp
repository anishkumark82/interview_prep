/*
Longest Palindromic Substring
*/
#include <iostream>
using namespace std;
// Bruteforce method
//O(n3)
void printPallindromeSubStrings(string s)
{
    for(int i = 0; i < s.size();i++)
    {
        for(int j = i; j < s.size();j++)
        {
            int start = i; int end = j;
            bool notPallin = false;
            while(start <= end)
            {
                //cout<<"Comparing :: "<<s[start]<<" "<<start<<" "<<s[end]<<" "<<end<<endl;
                if(s[start++] != s[end--])
                {
                    notPallin = true;
                    //cout<<"failed"<<endl;
                    break;
                }
            }
            if(!notPallin)
            {
                string s1 = s.substr(i, j-i+1);
                cout<<s1<<endl;
            }
        }

    }

}

int main()
{
    string sam;
    cin>>sam;

    printPallindromeSubStrings(sam);

    return 0;
}
