#include <stdio.h>

#define Vertex 4
#define Edges 5

struct Edge
{
    int start;
    int end;
    int weight;
};

int parent[Vertex];

int find(int vertex) // find parent of vertex
{
    while (parent[vertex] != vertex)
    {
        vertex = parent[vertex];
    }
    return vertex;
}

void union_of_sets(int u, int v) // join two sets
{
    parent[find(u)] = find(v);
}

void main()
{
    // sort by weight
    struct Edge edges[Edges] = {
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 5},
        {0, 3, 6},
        {2, 3, 7}};

    for (int i = 0; i < Vertex; i++)
    {
        parent[i] = i; // at first every vertex is its own parent
    }
    int count_edges = 0;

    for (int i = 0; i < Edges && count_edges < Vertex - 1; i++)
    {
        int u = find(edges[i].start);
        int v = find(edges[i].end);

        if (u != v) // both belongs to diff sets or else cycle will be created
        {
            printf("\n%d -> %d, %d", edges[i].start, edges[i].end, edges[i].weight);
            union_of_sets(u, v);
            count_edges++;
        }
    }
}