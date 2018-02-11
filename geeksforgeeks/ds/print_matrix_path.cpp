/*
Print All Paths from Top left to bottom right in Two Dimensional Array
*/
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

void printAllPaths(vector<vector<int>> path_id, int r, int c, string path)
{
    if(r == path_id.size()-1)
    {
        for(int i = c; i < path_id[0].size(); i++)
        {
            std::ostringstream oss;
            oss << path_id[r][i];
            path = path + "-" + oss.str();
        }
        cout<<path<<endl;
    }
    else if(c == path_id[0].size()-1)
    {
        for(int i = r; i < path_id.size(); i++)
        {
            std::ostringstream oss;
            oss << path_id[i][c];
            path = path + "-" + oss.str();
        }
        cout<<path<<endl;
    }
    else
    {
        std::ostringstream oss;
        oss << path_id[r][c];
        path = path + "-" + oss.str();
        printAllPaths(path_id,r+1,c, path);
        printAllPaths(path_id,r,c+1, path);
    }
    return;
}
int main()
{
    int m = 3, n = 3;
    vector<vector<int>> path_id(m,vector<int>(n));

    int c = 1;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            path_id[i][j] = c++;
        }
    }
    string path ="";
    printAllPaths(path_id, 0, 0,path);
}
