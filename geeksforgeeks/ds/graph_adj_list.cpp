#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
class Graph
{
    int numV;
    bool directed;
    // Assuming unweighted graph. If weighted graph then add a structure adjNode
    list<int> *mAdj;
public:
    Graph(int nV, bool di = false):
            numV(nV), directed(di)
    {
        mAdj = new list<int>[nV];
    }
    ~Graph()
    {
        // Need to deallocate the edge list
        for(int i = 0; i < numV; i++)
        {
            mAdj[i].clear();
        }
        delete[] mAdj;
    }

    void addEdge(int i, int j)
    {
        if(i >= numV || j >= numV)
        {
            return;
        }
        // Can add a find a function
        if(find(mAdj[i].begin(), mAdj[i].end(), j) != mAdj[i].end())
        {
            cout<<"edge already inserted"<<endl;
            return;
        }

        mAdj[i].push_back(j);
        if(!directed)
            mAdj[j].push_back(i);
    }

    void removeEdge(int i, int j)
    {
        if(i >= numV || j >= numV)
        {
            return;
        }

        mAdj[i].remove(j);
        if(!directed)
            mAdj[j].remove(i);
    }

    void printGraph()
    {
        for(int i = 0; i < numV; i++)
        {
            cout<<"Vertice : "<<i<<endl;
            for(list<int>::iterator itr = mAdj[i].begin(); itr != mAdj[i].end(); itr++)
            {
                cout<<*itr<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph *G = new Graph(5, false);
    G->printGraph();

    G->addEdge(0, 1);
    G->addEdge(2, 1);
    G->addEdge(0, 2);
    G->addEdge(2, 3);
    G->addEdge(4, 2);
    G->addEdge(1, 4);
    G->addEdge(2, 4);

    G->printGraph();
    G->removeEdge(2, 4);
    G->printGraph();

    delete G;
    return 0;
}
