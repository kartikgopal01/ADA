#include<stdio.h>

int no_edges = 1, cost[10][10];

int main() {
    int n, a, b, u, v, min, mincost = 0, parent[10];
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the cost matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        parent[i] = 0;
    }
    
    while (no_edges < n) {
        min = 999;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        while (parent[u]) {
            u = parent[u];
        }
        while (parent[v]) {
            v = parent[v];
        }
        
        if (u != v) {
            printf("Edge %d: (%d -> %d) cost = %d\n", no_edges++, a, b, min);
            mincost += min;
            parent[v] = u;
        }
        
        cost[a][b] = cost[b][a] = 999;
    }
    
    printf("Minimum cost = %d\n", mincost);
    
    return 0;
}
