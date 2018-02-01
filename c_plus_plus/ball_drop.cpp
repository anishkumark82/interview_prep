/*
Question 4

This one is a little more challenging. Write a short program to simulate a ball being dropped off of a tower. To start, the user should be asked for the initial height of the tower in meters. Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity (the ball is not moving to start). Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds. The ball should not go underneath the ground (height 0).

Your program should include a header file named constants.h that includes a namespace called myConstants. In the myConstants namespace, define a symbolic constant to hold the value of gravity (9.8). See section 2.9 -- Symbolic constants and the const keyword for a reminder on how to do this.

Use a function to calculate the height of the ball after x seconds. The function can calculate how far the ball has fallen after x seconds using the following formula:
distance fallen = gravity_constant * x_seconds2 / 2

Sample output:

Enter the initial height of the tower in meters: 100
At 0 seconds, the ball is at height: 100 meters
At 1 seconds, the ball is at height: 95.1 meters
At 2 seconds, the ball is at height: 80.4 meters
At 3 seconds, the ball is at height: 55.9 meters
At 4 seconds, the ball is at height: 21.6 meters
At 5 seconds, the ball is on the ground.
*/

#include <iostream>

namespace constants
{
    const float gravity = 9.8;
}

using namespace std;
using namespace constants;

void distanceFallen(int ht)
{
    float dist = 0.0;
    for(int t = 0; dist < ht; t++)
    {
        dist = constants::gravity * t*t/2;
        if(dist >= ht)
        {
            cout<<t<<" seconds, the ball is on the ground. "<<endl;
        }
        else
        {
            cout<<t<<" seconds, the ball is at height: "<<ht - dist<<endl;
        }
    }
}

int main()
{
    int ht;
    cout<<"Height in meters : ";
    cin>>ht;

    distanceFallen(ht);
    return 0;
}
