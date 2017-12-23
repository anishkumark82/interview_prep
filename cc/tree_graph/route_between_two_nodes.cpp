/*
4.1 Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a
route between two nodes.
*/

#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
class Graph
{

    int numVertices;
    list<int> *mAdj;
    bool directed;
public:
    Graph()
    {
        directed = false;
        numVertices = 0;
    }
    Graph(int numVertices, bool diGraph=true)
    {
        this->directed = diGraph;
        this->numVertices = numVertices;
        mAdj = new list<int>[numVertices];
    }
    ~Graph()
    {
        for(int i = 0; i < numVertices; i++)
        {
            mAdj[i].clear();
        }
        delete[] mAdj;
    }
    void addEdge(int u, int v)
    {
        if((u < numVertices) && (v < numVertices))
        {
            mAdj[u].push_back(v);
            mAdj[u].sort();
            mAdj[u].unique();

            if(!directed)
            {
                mAdj[v].push_back(u);
                mAdj[v].sort();
                mAdj[v].unique();
            }
        }
    }
    void removeEdge(int u, int v)
    {
        mAdj[u].remove(v);
        if(!directed)
        {
            mAdj[v].remove(u);
        }
    }

    bool findPathUtil(int s, int e, vector<bool> &visited)
    {
        visited[s] = true;
        bool found = false;
        if(s==e)
            return true;
        for(list<int>::iterator itr = mAdj[s].begin(); itr != mAdj[s].end() && !found; itr++)
        {
            if(!visited[*itr])
            {
                found = findPathUtil(*itr, e, visited);
                if(found)
                    break;
            }
        }
        return found;
    }
    bool findPath(int s, int e)
    {
        vector<bool>visited(numVertices, false);

        return findPathUtil(s,e,visited);
    }

    void printGraph()
    {
        cout<<"Graph data :: "<<endl;

        for(int i = 0; i < numVertices; i++)
        {
            cout<<"Vertex :: "<<i<<endl;
            for(list<int>::iterator itr = mAdj[i].begin(); itr != mAdj[i].end(); itr++)
                cout<<*itr<<" ";
            cout<<endl;
        }
    }
};

int main()
{
    Graph *G = new Graph(6, true);
    //G->printGraph();

    G->addEdge(0, 3);
    G->addEdge(0, 4);
    G->addEdge(3, 2);
    G->addEdge(2, 1);
    G->addEdge(1, 0);
    G->addEdge(4, 5);

    G->printGraph();
    //G->removeEdge(2, 4);
    //G->printGraph();
    cout<<"Path between 0 => 5 "<<G->findPath(0, 5)<<endl;
    cout<<"Path between 5 => 3 "<<G->findPath(5, 3)<<endl;
    cout<<"Path between 4 => 3 "<<G->findPath(4, 3)<<endl;
    cout<<"Path between 1 => 5 "<<G->findPath(1, 5)<<endl;

    delete G;

}
