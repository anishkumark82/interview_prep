/*
Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
void rotate_matrix(vector<vector<int>> &a)
{
    // Rotate layer by layer for each index
    //int layer = 0; // top most layer
    int n = a.size(); // N of the matrix
    for(int i = 0; i < n/2;i++)
    {
        int last = n - 1 - i;
        for(int j = i; j < last; j++)
        {
            //cout<<"j : "<<j<<endl;
            //perform rotation of indexes in that layer
            int top = a[i][j];

            // rotate left to top
            a[i][j] = a[n-1-j][i];

            // rotate bottom to left
            a[n-1-j][i] = a[n-1-i][n-1-j];
            // rotate right to bottom
            a[n-1-i][n-1-j] = a[j][n-1-i];
            // rotate top to right
            a[j][n-1-i] = top;
        }
    }
}

void print_matrix(vector<vector<int>> a)
{
    cout<<"Matrix data :" <<endl;
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < a[0].size(); j++)
        {
            printf("%4d",a[i][j]);
        }
        cout<<endl;
    }

}

int main()
{
    vector<vector<int>>a = {
                            {0, 1, 2, 3},
                            {4, 5, 6, 7},
                            {8, 9, 10, 11},
                            {12, 13, 14, 15}
    };
    cout<<"Before rotation"<<endl;
    print_matrix(a);

    rotate_matrix(a);
    cout<<"After rotation"<<endl;
    print_matrix(a);
}
