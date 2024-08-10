#include <stdio.h>
#define INF 9999999

int main()
{
    int cost[10][10], n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (i == j)
            {
                cost[i][j] = 0; // self-loop cost is 0
            }
            else if (cost[i][j] == 0)
            {
                cost[i][j] = INF;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((cost[i][k] + cost[k][j]) < cost[i][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
            }
        }
    }
    printf("Shortest path matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
    return 0;
}