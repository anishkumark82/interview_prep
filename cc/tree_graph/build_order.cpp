/*
4.7 Build Order: You are given a list of projects and a list of dependencies (which is a list of pairs of
projects, where the second project is dependent on the first project). All of a project's dependencies
must be built before the project is. Find a build order that will allow the projects to be built. If there
is no valid build order, return an error.
EXAMPLE
Input:
projects: a, b, c, d, e, f
dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
*/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

typedef struct
{
    char project;
    list<char> adjList;
}graphNode;
class Graph
{
    int numV;
    bool diGraph;
    graphNode *pVArray; // pointer to the array of nodes;

public:
    Graph():
        numV(0),
        diGraph(false)
    {
        pVArray = NULL; // pointer to the array of nodes;
    }
    Graph(int V, bool directed):
        numV(V),
        diGraph(directed)
    {
        pVArray = new graphNode[V]; // pointer to the array of nodes;
        int j; char i;
        for(i = 'a', j = 0; j < V;i++,j++)
        {
            pVArray[j].project = i;
        }
    }
    ~Graph()
    {
        for(int i = 0;i < numV; i++)
        {
            pVArray[i].adjList.clear();
        }
        delete[] pVArray;
    }
    int getGraphNodeIndex(char u)
    {
        for(int i = 0; i < numV; i++)
        {
            if(pVArray[i].project == u)
            {
                return i;
            }
        }
        return -1;
    }
    bool checkIncomingEdgetoNode(char v)
    {
        for(int i = 0; i < numV; i++)
        {
            list<char>::iterator itr;
            // Assuming no dependency to itself
            if(pVArray[i].project == v)
            {
                continue;
            }
            for(itr = pVArray[i].adjList.begin(); itr != pVArray[i].adjList.end(); itr++)
            {
                if(*itr == v)
                {
                    //cout<<"Incoming edge from "<<pVArray[i].project<<" to "<<v<<endl;
                    return true;
                }

            }
        }
        return false;
    }
    void addEdge(char u, char v)
    {
        int nodeIdx = getGraphNodeIndex(u);

        if(nodeIdx != -1)
        {
            pVArray[nodeIdx].adjList.push_back(v);
        }
    }

    void removeAllEdge(char u)
    {
        int nodeIdx = getGraphNodeIndex(u);
        pVArray[nodeIdx].adjList.clear();
    }

    void removeEdge(char u, char v)
    {
        int nodeIdx = getGraphNodeIndex(u);

        if(nodeIdx != -1)
        {
            pVArray[nodeIdx].adjList.remove(v);
        }
    }

    bool buildDependency(list<char> &dependencyList)
    {
        while(dependencyList.size() < numV)
        {
            int before_size = dependencyList.size();
            for(int i = 0; i < numV; i++)
            {
                bool incomingEdge = checkIncomingEdgetoNode(pVArray[i].project);
                if(!incomingEdge)
                {
                    list<char>::iterator itr = dependencyList.begin();
                    bool alreadyAdded = false;
                    for(;itr != dependencyList.end();itr++)
                    {
                        if(*itr == pVArray[i].project)
                        {
                            alreadyAdded = true;
                            break;
                        }
                    }
                    if(!alreadyAdded)
                    {
                        dependencyList.push_back(pVArray[i].project);
                        removeAllEdge(pVArray[i].project);
                    }
                }
            }
            int after_size = dependencyList.size();
            if(before_size == after_size)
            {
                cout<<"Deadlock cannot resolve build dependencies"<<endl;
                return false;
            }
        }
        return true;
    }
};

int main()
{
    //a, b, c, d, e, f
    Graph *G = new Graph(6, true);
    //(a, d), (f, b), (b, d), (f, a), (d, c)
    G->addEdge('a','d');
    G->addEdge('f','b');
    G->addEdge('b','d');
    G->addEdge('f','a');
    G->addEdge('d','c');

    list<char> dependencyList;
    bool isSolvable = G->buildDependency(dependencyList);
    if(isSolvable)
    {
        cout<<"Build order : "<<endl;
        for (list<char>::iterator i = dependencyList.begin(); i != dependencyList.end();i++)
        {
            cout<<*i<<" ";
        }
        cout<<endl;
    }
    delete G;
    return 0;
}
