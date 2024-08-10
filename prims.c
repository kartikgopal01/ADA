#include<stdio.h>

int main() {
    int i, j, ne = 1, n, source, target, min, mincost = 0;
    int cost[10][10], visited[10], parent[10];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize parent array
    for(i = 0; i < n; i++) {
        parent[i] = 0;
    }

    // Input cost matrix
    printf("Enter the cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize visited array
    for(i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Input source vertex
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    visited[source] = 1;

    while(ne < n) {
        min = 999;

        // Find the minimum edge from the visited set
        for(i = 0; i < n; i++) {
            if(visited[i]) {
                for(j = 0; j < n; j++) {
                    if(cost[i][j] < min && !visited[j]) {
                        min = cost[i][j];
                        source = i;
                        target = j;
                    }
                }
            }
        }

        // Mark the target vertex as visited and add the edge to the MST
        visited[target] = 1;
        printf("Edge %d: (%d -> %d) cost = %d\n", ne++, source, target, min);
        mincost += min;
    }

    printf("Minimum cost of spanning tree: %d\n", mincost);

    return 0;
}
