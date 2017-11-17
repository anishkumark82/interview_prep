#include <iostream>
#include <algorithm>
using namespace std;
/* Example 1 : Consider the following 3 activities sorted by
by finish time.
     start[]  =  {10, 12, 20};
     finish[] =  {20, 25, 30};
A person can perform at most two activities. The
maximum set of activities that can be executed
is {0, 2} [ These are indexes in start[] and
finish[] ]
*/
/* O(nlogn) if activity not sorted based on finish time
   O(n) if activity sorted based on finish time
 */
typedef struct
{
    int start;
    int end;
} activity_t;
bool activityCompare(activity_t a, activity_t b)
{
    return (a.end < b.end);
}
void printMaxActivities(activity_t activity[], int n)
{
    /* sort the activity in ascending order of finish time */
    sort(activity, activity+n, activityCompare);

    int i = 0;
    cout<<"start: "<<activity[i].start<<" end : "<<activity[i].end<<endl;
    for (int j = 0; j < n ; j++)
        if (activity[i].end <= activity[j].start)
        {
            i = j;
            cout<<"start: "<<activity[i].start<<" end : "<<activity[i].end<<endl;
        }
 }
int main()
{
    /*
    activity_t activity[] = {{10,20}, {12,25}, {20,30}};
    */
    activity_t activity[] = {{1,2}, {3,4}, {0,6}, {5,7}, {8,9}, {5,9}};

    printMaxActivities(activity, sizeof(activity)/sizeof(activity[0]));

}
