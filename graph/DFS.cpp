//DFS Graph algorithm

#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Graph
{
private:
    int numVertex;
    bool digraph;
    list<int>* adj;

public:
    Graph()
    {

    }
    Graph(int V, bool di = false)
    {
        numVertex = V;
        adj = new list<int>[V];
    }
    ~Graph()
    {
        // Remove the edges
        for(int i = 0; i < numVertex; i++)
            adj[i].clear();
        delete[] adj;
    }

    void addEdge(int i, int j)
    {
        if (i < numVertex && j < numVertex)
        {
            adj[i].push_back(j);
            if(!digraph)
                adj[j].push_back(i);

            // to ensure an edge is not inserted multiple times
            adj[i].sort();
            adj[i].unique();
            adj[j].sort();
            adj[j].unique();
        }
    }
    void removeEdge(int i, int j)
    {
        if (i < numVertex && j < numVertex)
        {
            adj[i].remove(j);
            if(!digraph)
                adj[j].remove(i);
        }
    }
    void DFSUtil(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout<<v<<" ";
        for(list<int>::iterator itr = adj[v].begin(); itr != adj[v].end(); itr++)
            if(!visited[(*itr)])
                DFSUtil(*itr, visited);
    }
    void DFS(int s)
    {
        cout<<"DFS:: start node :: "<<s<<endl;
        vector<bool> visited(numVertex, false);
        DFSUtil(s, visited);
        cout<<endl;
    }
    void printGraph()
    {
        cout<<"Graph data :: "<<endl;

        for(int i = 0; i < numVertex; i++)
        {
            cout<<"Vertex :: "<<i<<endl;
            for(list<int>::iterator itr = adj[i].begin(); itr != adj[i].end(); itr++)
                cout<<*itr<<" ";
            cout<<endl;
        }
    }

};

int main()
{
    Graph *G = new Graph(5, false);
    //G->printGraph();

    G->addEdge(0, 1);
    G->addEdge(2, 1);
    G->addEdge(0, 2);
    G->addEdge(2, 3);
    G->addEdge(4, 2);
    G->addEdge(1, 4);
    G->addEdge(2, 4);

    G->printGraph();
    //G->removeEdge(2, 4);
    //G->printGraph();
    G->DFS(2);
    G->DFS(0);
    delete G;

}
