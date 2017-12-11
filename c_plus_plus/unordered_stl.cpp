#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    // unordered set
    unordered_set<string> color_set = {"red", "green", "nir", "fir"};
    unordered_set<string>::iterator itr = color_set.find("green"); // O(1)

    if(itr != color_set.end())
    {
        cout<<"found itr for "<<*itr<<endl;
    }

    itr = color_set.find("yellow");
    if(itr == color_set.end())
    {
        cout<<"failed to find itr for yellow"<<endl;
    }
    color_set.insert("yellow"); // O(1)

    // Special functions of unordered containers
    cout<<"load factor of the hash table :: "<<color_set.load_factor()<<endl;

    cout<<"bucket id for green "<<color_set.bucket("green")<<endl;
    // unordered multiset allows duplicates

    cout<<"bucket count for hash :: "<<color_set.bucket_count()<<endl;

    vector<string> color_array = {"pink", "blue", "white", "peach"};
    color_set.insert(color_array.begin(), color_array.end());

    cout<<"after array insertion"<<endl;
    // Special functions of unordered containers
    cout<<"load factor of the hash table :: "<<color_set.load_factor()<<endl;

    cout<<"bucket id for green "<<color_set.bucket("green")<<endl;
    // unordered multiset allows duplicates

    cout<<"bucket count for hash :: "<<color_set.bucket_count()<<endl;


    return 0;
}
