// Adjacency List representation of graph
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef struct _edge_t
{
    int v;
    _edge_t *next;
}edge_t;
typedef struct
{
    int vertex;
    edge_t *edgeList;
}adjList_t;
typedef struct
{
    int numVertex;
    adjList_t *adjList;
    bool digraph;
}graph_t;

graph_t *createGraph(int numVertex, bool digraph = false)
{
    graph_t *G = (graph_t *) malloc (sizeof(graph_t));
    if (G)
    {
        G->numVertex = numVertex;
        G->adjList = (adjList_t *) malloc (sizeof(adjList_t)*numVertex);
        for (int i = 0; i < numVertex; i++)
        {
            G->adjList[i].vertex = i;
            G->adjList[i].edgeList = NULL;
        }
    }

    return G;
}

void destroyGraph(graph_t *G)
{
    for (int i = 0; i < G->numVertex; i++)
        while(G->adjList[i].edgeList)
        {
            edge_t *temp = G->adjList[i].edgeList;
            G->adjList[i].edgeList = G->adjList[i].edgeList->next;
            free(temp);
        }

    free(G->adjList);
    free(G);
}

void printGraph(graph_t *G)
{
    cout<<"Num Vertex : "<<G->numVertex<<endl;
    cout<<"Is Digraph : "<<G->digraph<<endl;

    for(int i = 0; i < G->numVertex; i++)
    {
        cout<<"Edge list for vertex : "<<G->adjList[i].vertex<<endl;
        edge_t *temp = G->adjList[i].edgeList;
        while(temp)
        {
            cout<<temp->v<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

}
// TBD could add code to remove duplicates
void addEdge(graph_t *G, int i, int j)
{
    // Adding edge to the front - Can add to the rear also. If front O(1) for insert
    if(i < G->numVertex && j < G->numVertex)
    {
        edge_t *temp = (edge_t *) malloc (sizeof(edge_t));
        temp->v = j;
        temp->next = G->adjList[i].edgeList;
        G->adjList[i].edgeList = temp;

        if(!G->digraph)
        {
            edge_t *temp = (edge_t *) malloc (sizeof(edge_t));
            temp->v = i;
            temp->next = G->adjList[j].edgeList;
            G->adjList[j].edgeList = temp;

        }
    }
}

void removeEdge(graph_t *G, int i, int j)
{

    if(i < G->numVertex && j < G->numVertex)
    {
        edge_t *temp =  G->adjList[i].edgeList;
        if(!temp)
            return;
        // If head node to be deleted
        if(G->adjList[i].edgeList->v == j)
        {
            G->adjList[i].edgeList = G->adjList[i].edgeList->next;
            free(temp);
        }
        else
        {
            while(temp->next)
            {
                if(temp->next->v == j)
                {
                    edge_t *temp2 = temp->next;
                    temp->next = temp2->next;
                    free(temp2);
                    break;
                }
                temp = temp->next;
            }
        }
        if(!G->digraph)
        {
            edge_t *temp =  G->adjList[j].edgeList;
            if(!temp)
                return;

            // If head node to be deleted
            if(G->adjList[j].edgeList->v == i)
            {
                G->adjList[j].edgeList = G->adjList[j].edgeList->next;
                free(temp);
            }
            else
            {
                while(temp->next)
                {
                    if(temp->next->v == i)
                    {
                        edge_t *temp2 = temp->next;
                        temp->next = temp2->next;
                        free(temp2);
                        break;
                    }
                    temp = temp->next;
                }
            }
        }
    }
}

int main()
{
    graph_t *G = createGraph(5);
    printGraph(G);

    addEdge(G, 0, 1);
    addEdge(G, 2, 1);
    addEdge(G, 0, 2);
    addEdge(G, 2, 3);
    addEdge(G, 4, 2);
    addEdge(G, 1, 4);
    printGraph(G);
    removeEdge(G, 2, 4);
    printGraph(G);

    destroyGraph(G);
    return 0;
}

