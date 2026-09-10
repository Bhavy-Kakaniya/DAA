#include <stdio.h>

int main() {
    int n, graph[100][100];
    int start, mid, destination;

    scanf("%d", &n);

    for (start = 0; start < n; start++)
        for (destination = 0; destination < n; destination++)
            scanf("%d", &graph[start][destination]);

    for (mid = 0; mid < n; mid++)
        for (start = 0; start < n; start++)
            for (destination = 0; destination < n; destination++)
                graph[start][destination] = graph[start][destination] || (graph[start][mid] && graph[mid][destination]);

    for (start = 0; start < n; start++) {
        for (destination = 0; destination < n; destination++)
            printf("%d ", graph[start][destination]);
        printf("\n");
    }
}