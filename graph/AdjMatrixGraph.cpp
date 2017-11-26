// Adjacency Matrix Graph representation
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef struct
{
    int numVertex;
    int *vertex;
    int **edge;
    bool digraph;
}graph_t;

graph_t *createGraph(int numVertex, bool digraph = false)
{
    graph_t *G = (graph_t *) malloc (sizeof(graph_t));
    if (G)
    {
        G->numVertex = numVertex;
        G->vertex = (int *) malloc (sizeof(int)*numVertex);
        for (int i = 0; i < numVertex; i++)
            G->vertex[i] = i;
        // Create the n x n adjacency matrix
        G->edge = (int **) malloc (sizeof(int *) * numVertex);
        for(int i = 0; i < numVertex; i++)
        {
            G->edge[i] = (int *) malloc (sizeof(int) * numVertex);
            memset(G->edge[i], 0, sizeof(int)* numVertex);
        }
    }

    return G;
}

void destroyGraph(graph_t *G)
{
    for(int i = 0; i < G->numVertex; i++)
        free(G->edge[i]);
    free(G->edge);
    free(G->vertex);
    free(G);
}

void printGraph(graph_t *G)
{
    cout<<"Num Vertex : "<<G->numVertex<<endl;
    cout<<"Is Digraph : "<<G->digraph<<endl;
    cout<<"Vertex list : "<<endl;
    for(int i = 0; i < G->numVertex; i++)
        cout<<" "<<G->vertex[i];
    cout<<"\nEdge Matrix : "<<endl;
    for(int i = 0; i < G->numVertex; i++)
        for(int j = 0; j < G->numVertex; j++)
            cout<<" "<<G->edge[i][j];
    cout<<endl;

}
void addEdge(graph_t *G, int i, int j)
{
    if(i < G->numVertex && j < G->numVertex)
    {
        G->edge[i][j] = 1;
        if(!G->digraph)
            G->edge[j][i] = 1;
    }
}

void removeEdge(graph_t *G, int i, int j)
{
    if(i < G->numVertex && j < G->numVertex)
    {
        G->edge[i][j] = 0;
        if(!G->digraph)
            G->edge[j][i] = 0;
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
    addEdge(G, 2, 4);
    printGraph(G);
    removeEdge(G, 2, 4);
    printGraph(G);

    destroyGraph(G);
    return 0;
}
