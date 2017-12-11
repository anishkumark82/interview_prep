#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <array>
using namespace std;
int main()
{
    // vectors
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vector<int>::iterator itr;

    cout<<vec[3]<<endl; // no out of bound check

    try {
        cout<<vec.at(5);
    }
    catch(const exception &e)
    {
        cout<<"Throwing exception "<<e.what()<<endl;
    }

   for(itr = vec.begin(); itr != vec.end(); itr++)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;
    // deque
    deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_front(3);
    deq.push_front(4);
    deque<int>::iterator deqItr;
    cout<<deq[3]<<endl; // no out of bound check

    try {
        cout<<deq.at(5);
    }
    catch(const exception &e)
    {
        cout<<e.what()<<endl;
    }
    for(deqItr = deq.begin(); deqItr != deq.end(); deqItr++)
    {
        cout<<*deqItr<<" ";
    }
    cout<<endl;

    // list
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_front(3);
    lt.push_front(4);
    list<int>::iterator ltItr;
    // Subscript not supported
    for(ltItr = lt.begin(); ltItr != lt.end(); ltItr++)
    {
        cout<<*ltItr<<" ";
    }
    cout<<endl;
    list<int> lt2;
    list<int>::iterator lt2Itr = lt2.begin();
    list<int>::iterator ltItr_a = find(lt.begin(), lt.end(), 3);
    list<int>::iterator ltItr_b = find(lt.begin(), lt.end(), 2);

    lt2.splice(lt2Itr, lt, ltItr_a,ltItr_b);
    // Subscript not supported
    cout<<"list2 after splice"<<endl;
    for(lt2Itr = lt2.begin(); lt2Itr != lt2.end(); lt2Itr++)
    {
        cout<<*lt2Itr<<" ";
    }
    cout<<endl;

    // Subscript not supported
    cout<<"list1 after splice"<<endl;
    for(ltItr = lt.begin(); ltItr != lt.end(); ltItr++)
    {
        cout<<*ltItr<<" ";
    }
    cout<<endl;

    // forward list similar to list - implementation done using single link list

    array<int, 3> arr= {1,2,3};
    array<int,3>::iterator arrItr;
    for(arrItr = arr.begin(); arrItr != arr.end(); arrItr++)
    {
        cout<<*arrItr<<" ";
    }
    cout<<endl;
    return 0;
}
