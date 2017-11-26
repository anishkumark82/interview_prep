// C++ Implementation of adj List
// Breadth first search

#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;
class Graph
{
private:
    int mNumVertex;
    list <int> *mAdj; //Pointer to the to edge list. Create an array of pointers
    bool mDigraph;
public:
    Graph()
    {
        mNumVertex = 0;
        mDigraph = false;
        mAdj = NULL;
    }
    Graph(int V, bool diGraph = false)
    {
        mNumVertex = V;
        mDigraph = diGraph;
        //create an array of edge lists
        mAdj = new list<int>[V];
    }
    ~Graph()
    {
        // Remove the edges
        for(int i = 0; i < mNumVertex; i++)
            mAdj[i].clear();
        delete[] mAdj;
    }
    void addEdge(int i, int j)
    {
        if(i < mNumVertex && j < mNumVertex)
        {
            mAdj[i].push_back(j);
            if(!mDigraph)
                mAdj[j].push_back(i);
        }
        // rempve duplicates
        mAdj[i].sort();
        mAdj[i].unique();
        mAdj[j].sort();
        mAdj[j].unique();
    }

    void removeEdge(int i, int j)
    {
        if(i < mNumVertex && j < mNumVertex)
        {
            mAdj[i].remove(j);
            if(!mDigraph)
                mAdj[j].remove(i);
        }
    }
    void printGraph()
    {
        cout<<"Graph data :: "<<endl;

        for(int i = 0; i < mNumVertex; i++)
        {
            cout<<"Vertex :: "<<i<<endl;
            for(list<int>::iterator itr = mAdj[i].begin(); itr != mAdj[i].end(); itr++)
                cout<<*itr<<" ";
            cout<<endl;
        }
    }
    void BFS(int s = 0)
    {
        cout<<"Breadth first Search -> s :: "<<s<<endl;
        vector<bool> visited(mNumVertex, false);
        queue<int>Q;
        Q.push(s);
        while(!Q.empty())
        {
            if(visited[Q.front()] != true)
            {
                cout<<Q.front()<<" ";
                for(list<int>::iterator itr = mAdj[Q.front()].begin(); itr != mAdj[Q.front()].end(); itr++)
                    Q.push(*itr);
                visited[Q.front()] = true;
            }
            Q.pop();
        }
        cout<<endl;
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
    G->BFS(2);
    G->BFS(0);
    delete G;

}
