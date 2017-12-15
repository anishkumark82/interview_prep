/*
URLify: Write a method to replace all spaces in a string with '%20: You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true"
length of the string. (Note: If implementing in Java, please use a character array so that you can
perform this operation in place.)
EXAMPLE
Input: "Mr John Smith ", 13
Output: "Mr%20John%20Smith"
*/
#include <iostream>
#include <cstring>
using namespace std;
void URLify(char s[], int s_size)
{
    // Assuming s_size is true length
    // find the number of spaces in the string
    int space_count = 0;
    for(int i = 0; i < s_size; i++)
    {
        if(s[i] == ' ')
        {
            space_count++;
        }
        cout<<space_count<<endl;
    }

    // O(n) solution
    for(int i = s_size-1; i >= 0; i--)
    {
        if(s[i] != ' ')
            s[i + (space_count * 2)] = s[i];
        else
        {
            s[i + (space_count * 2)] = '0';
            s[i + (space_count * 2)-1] = '2';
            s[i + (space_count * 2)-2] = '%';
            space_count--;
        }
        if(space_count == 0)
            break;
    }
    cout<<s;
}

int main()
{
    char input[100] = {0};
    strcpy(input, "Mr John Smith");
    URLify(input, strlen(input));
    return 0;
}
