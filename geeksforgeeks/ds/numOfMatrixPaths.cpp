#include<iostream>
#include<vector>

using namespace std;
int numOfPaths(int r, int c, int numR, int numC)
{

    if((r == numR-1) || (c == numC -1))
    {
        return 1;
    }
    return numOfPaths(r+1, c, numR, numC) + numOfPaths(r, c+1, numR, numC);
}

int numOfPathsDyn(vector<vector<int>> &path_count, int r, int c)
{
    if(r < path_count.size() && c < path_count[0].size())
    {
        if(path_count[r][c] == -1)
        {
            path_count[r][c] = numOfPathsDyn(path_count, r+1, c) + numOfPathsDyn(path_count, r, c+1);
        }
        return path_count[r][c];
    }
    return 0;
}
int main()
{
    int m =3, n = 3;
    vector<vector<int>>path_count(m,vector<int>(n,-1));
    for(int i = 0; i < m; i++)
    {
        path_count[i][n-1] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        path_count[m-1][i] = 1;
    }
    cout<<numOfPathsDyn(path_count,0,0);

    return 0;
}
