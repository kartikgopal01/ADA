#include<stdio.h> 
void main() 
{ 
    int i,j,k,cost[10][10],n; 
    printf("enter the number of vertices"); 
    scanf("%d",&n); 
    printf("enter the cost matric"); 
    for(i=1;i<=n;i++) 
    { 
        for(j=1;j<=n;j++) 
        { 
            scanf("%d",&cost[i][j]); 
        } 
    } 
    for(k=1;k<=n;k++) 
    { 
        for(i=1;i<=n;i++) 
        { 
            for(j=1;j<=n;j++) 
            { 
                if((cost[i][k]+cost[k][j])<cost[i][j]) 
                cost[i][j]=cost[i][k]+cost[k][j]; 
            } 
        } 
    } 
    printf("the edge with cost\n"); 
    for(i=1;i<=n;i++) 
    { 
        for(j=1;j<=n;j++) 
        { 
            printf("edge %d to %d ,cost is=%d\n",i,j,cost[i][j]); 
        } 
    } 
} 