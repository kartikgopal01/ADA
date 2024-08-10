#include <stdio.h>

void main() 
{ 
    int a[10][10], T[10][10]; 
    int n, i, j, k; 

    // Input number of vertices
    printf("Enter the number of vertices: "); 
    scanf("%d", &n); 

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n"); 
    for (i = 0; i < n; i++) 
    { 
        for (j = 0; j < n; j++) 
        { 
            scanf("%d", &a[i][j]); 
            T[i][j] = a[i][j]; // Initialize T with a's values
        } 
    } 

    // Floyd-Warshall algorithm to find transitive closure
    for (k = 0; k < n; k++) 
    { 
        for (i = 0; i < n; i++) 
        { 
            for (j = 0; j < n; j++) 
            { 
                T[i][j] = T[i][j] || (T[i][k] && T[k][j]); 
            } 
        } 
    } 

    // Print the transitive closure matrix
    printf("Transitive closure is:\n"); 
    for (i = 0; i < n; i++) 
    { 
        for (j = 0; j < n; j++) 
        { 
            printf("%d ", T[i][j]); 
        } 
        printf("\n"); 
    } 
}
