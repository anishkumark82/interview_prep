// Topological sort for DAG - directed Acyclic Graph

#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;
class Graph
{
private:
    int numVertex;
    list<int> *adj;
    bool diGraph;
public:
    Graph()
    {
    }
    ~Graph()
    {
        for(int i = 0; i < numVertex; i++)
            adj[i].clear();
        delete[]adj;
    }
    Graph(int V, bool di = true)
    {
        numVertex = V;
        diGraph = di;
        adj = new list<int>[V];
    }
    void addEdge(int i, int j)
    {
        if (i < numVertex && j < numVertex)
            adj[i].push_back(j);
    }

    void tSortUtil(int v, vector<bool> &visited, stack<int> &S)
    {
        visited[v] = true;
        //cout<<v<<" ";
        for(list<int>::iterator itr = adj[v].begin(); itr != adj[v].end(); itr++)
            if(!visited[*itr])
                tSortUtil(*itr, visited, S);
        S.push(v);
    }

    void longestPath()
    {
        stack<int> S;
        vector<bool>visited(numVertex, false);
        vector<int>dist(numVertex, INT_MIN);
        // Call the recursive helper function to store Topological
        // Sort starting from all vertices one by one - Basically do DFS for each of the nodes until all nodes are visited
        for(int i=0; i < numVertex; i++)
            if(!visited[i])
                tSortUtil(i, visited, S);

        while(!S.empty())
        {
            int u = S.top();
            S.pop();

        }
        cout<<endl;
    }
};

int main()
{

    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph : ";
    g.topologicalSort();
    return 0;
}
