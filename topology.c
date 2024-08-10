#include <stdio.h>

int main()
{
    int a[10][10], indegree[10] = {0}, i, j, n, count = 0;

    // Input number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the Adjacency Matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    // Topological sort
    printf("The Topological Sorted Order is:\n");
    while (count < n)
    {
        int found = 0;
        for (i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                printf("%d\t", i);
                indegree[i] = -1; // Mark node as processed
                count++;
                found = 1;
                for (j = 1; j <= n; j++)
                {
                    if (a[i][j] == 1)
                    {
                        indegree[j]--;
                    }
                }
                break; // Break the loop to restart from the first node
            }
        }
        if (!found)
        {
            printf("The graph has a cycle or no valid topological sort.\n");
            break;
        }
    }

    return 0;
}
