#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int weight[10], W, n, p[10], m[10][10];

void knapsack() {
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                m[i][j] = 0;
            } else if (j < weight[i - 1]) {
                m[i][j] = m[i - 1][j];
            } else {
                m[i][j] = (m[i - 1][j] > m[i - 1][j - weight[i - 1]] + p[i - 1]) ? m[i - 1][j] : m[i - 1][j - weight[i - 1]] + p[i - 1];
            }
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("%d", m[n][W]);
}

int main() {
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the maximum capacity of knapsack: ");
    scanf("%d", &W);
    printf("Enter the weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    printf("Enter the profits: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    knapsack();
    return 0;
}