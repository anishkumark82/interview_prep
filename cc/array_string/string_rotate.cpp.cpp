/*
String Rotation: Assume you have a method isSubst ring which checks if one word is a substring
of another. Given two strings, 51 and 52, write code to check if 52 is a rotation of 51 using only one
call to isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat").

*/
#include<iostream>
using namespace std;
bool isRotatedString(string str, string rotated_str)
{
    string newStr = str + str;

    size_t found = newStr.find(rotated_str);
    return (found != string::npos) && (rotated_str.size() == str.size());
}

int main()
{
    string str, rotated_str;
    cin>>str>>rotated_str;

    cout<<"isRotatedString() : "<<isRotatedString(str, rotated_str)<<endl;

    return 0;
}
