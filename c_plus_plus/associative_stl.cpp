#include<iostream>
#include<algorithm>
#include<map>
#include<set>
//#include<multimap>
//#include<multiset>

using namespace std;
int main()
{
    //sets
    // creates a sorted binary tree with the values
    set<int> s;
    s.insert(10); // 10
    s.insert(7);  // 7,10
    s.insert(3);  // 3,7,10
    s.insert(1);  // 1,3,7,10

    set<int>::iterator itr = s.find(7);
    cout<<*itr<<endl;

    pair<set<int>::iterator,bool> ret;
    ret = s.insert(3); // returns a pair with iterator and whether insert succeeded or not
    if(!ret.second)
    {
        cout<<"element already present :: "<<*(ret.first)<<endl;
    }

    // Print all the elements of the set
    cout<<"Print elements of the set"<<endl;
    for(itr=s.begin();itr!=s.end();itr++)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;

    //multi-set
    // same as set but allows duplicates
    multiset<int> ms;
    ms.insert(10); // 10
    ms.insert(7);  // 7,10
    ms.insert(3);  // 3,7,10
    ms.insert(1);  // 1,3,7,10
    ms.insert(3);
    ms.insert(10);
    // Print all the elements of the set
    cout<<"Print elements of the multiset"<<endl;
    multiset<int>::iterator mitr;
    for(mitr=ms.begin();mitr!=ms.end();mitr++)
    {
        cout<<*mitr<<" ";
    }
    cout<<endl;

    // maps
    // in maps each node of the binary tree contains key and value
    // binary tree sorted on the key

    map<char, int> mapNotoAlpha;
    mapNotoAlpha.insert(pair<char,int>('a',10));
    mapNotoAlpha.insert(pair<char,int>('b',25));
    mapNotoAlpha.insert(pair<char,int>('z',1));
    mapNotoAlpha.insert(pair<char,int>('d',35));
    mapNotoAlpha.insert(pair<char,int>('c',12));
    pair<map<char, int>::iterator,bool> retmap;
    retmap = mapNotoAlpha.insert(pair<char,int>('d',12));
    if(!retmap.second)
    {
        cout<<"element already present :: "<<retmap.first->second<<endl;
    }
    map<char,int>::iterator mapitr;
    for(mapitr=mapNotoAlpha.begin();mapitr!=mapNotoAlpha.end();mapitr++)
    {
        cout<<mapitr->first<<" => "<<mapitr->second<<" ";
    }
    cout<<endl;

    // multimap allows duplicates
    return 0;
}
