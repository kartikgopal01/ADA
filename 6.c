#include<stdio.h>
#include<math.h>

int W, w[10], p[10], m[10][10], n;

void knapsack1()
{
    int i, j;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= W; j++) 
        {
            if(i == 0 || j == 0)
            {
                m[i][j] = 0;
            }
            else if(w[i - 1] > j) 
            {
                m[i][j] = m[i - 1][j];
            }
            else
            {
                m[i][j] = fmax(m[i - 1][j], m[i - 1][j - w[i - 1]] + p[i - 1]); 
            }
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("The optimized value is: %d\n", m[n][W]);
}

void main()
{
    int i;
    printf("Enter the number of objects\n");
    scanf("%d", &n); 
    printf("Enter the maximum capacity of the knapsack\n");
    scanf("%d", &W); 
    printf("Enter the weights of the objects\n");
    for(i = 0; i < n; i++)
        scanf("%d", &w[i]); 
    printf("Enter the profits of the objects\n");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]); 
    knapsack1();
}