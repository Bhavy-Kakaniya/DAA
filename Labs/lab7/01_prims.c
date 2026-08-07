#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define Vertex 5

void main()
{
    int adjacencyMatrix[Vertex][Vertex];

    printf("Enter adjacency matrix: \n");
    for (int i = 0; i < Vertex; i++)
    {
        for (int j = 0; j < Vertex; j++)
        {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    bool visited[Vertex] = {false}; // initialises array with false
    int start, end;
    int count_edges = 0;

    visited[0] = 1;                  // starting from vertex 0
    while (count_edges < Vertex - 1) // because in spanning tree total edge = no of v - 1
    {
        int min_edge = INT_MAX; // reseting min weight of edge everytime

        for (int i = 0; i < Vertex; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < Vertex; j++) // check all vertices connected to current vertex
                {
                    if (!visited[j] && adjacencyMatrix[i][j] != 0)
                    {
                        if (adjacencyMatrix[i][j] < min_edge)
                        {
                            min_edge = adjacencyMatrix[i][j];
                            start = i;
                            end = j;
                        }
                    }
                }
            }
        }
        printf("%d -> %d, %d\n", start, end, adjacencyMatrix[start][end]);
        visited[end] = true;
        count_edges++;
    }
}