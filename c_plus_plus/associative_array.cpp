// Creating an associative array using unordered map

#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;
int main()
{
    unordered_map<char, string> days = {make_pair('M', "Monday"),make_pair('T', "Tuesday")};
    cout<<days['M']<<endl; // no boundary check
    cout<<days.at('M')<<endl; // boundary check available

    days['W'] = "Wednesday"; // makes writable and adds to the map

    days.insert(make_pair('F', "Friday"));

    pair<unordered_map<char, string>::iterator, bool> ret = days.insert(make_pair('M', "MONDAY")); // shall fail
    if(!ret.second)
    {
        cout<<"insert operation failed since already key mapped "<<ret.first->first<<" => "<<ret.first->second<<endl;
    }

    days['M'] = "MONDAY"; // shall succeed since subscript operator makes it writable
    cout<<days['M']<<endl; // no boundary check

    return 0;
}
