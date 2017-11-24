/* Rotate 90 degree clockwise */

/* a00 a01 a02
   a10 a11 a12
   a20 a21 a22 */

/* clockwise
   a20 a10 a00
   a21 a11 a01
   a22 a12 a02 */
#include <iostream>
using namespace std;

void print_rotate_90_clockwise(int a[][3], int n)
{
    for (int j = 0; j< n; j++)
    {
        cout<<endl;
        for (int i = n-1; i >=0; i--)
            cout<<a[i][j]<<" ";
    }
    cout<<endl;
}

/* a00 a01 a02
   a10 a11 a12
   a20 a21 a22 */

/* a02 a12 a22
   a01 a11 a21
   a00 a10 a20 */

void print_rotate_90_anticlockwise(int a[][3], int n)
{
    for (int j = n-1; j >= 0; j--)
    {
        cout<<endl;
         for (int i = 0; i < n; i++)
            cout<<a[i][j]<<" ";
    }
    cout<<endl;

}

void print_rotate_180(int a[][3], int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        cout<<endl;
         for (int j = n-1; j >= 0; j--)
            cout<<a[i][j]<<" ";
    }
    cout<<endl;

}

// Driven code
int main()
{
    int mat[3][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    cout<<"Rotate matrix 90 clockwise";
    print_rotate_90_clockwise(mat, 3);
    cout<<"Rotate matrix 90 anti-clockwise";
    print_rotate_90_anticlockwise(mat, 3);
    cout<<"Rotate matrix 180";
    print_rotate_180(mat, 3);

    return 0;
}
