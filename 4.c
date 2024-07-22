#include<stdio.h>

void dijk(int n,int cost[10][10],int dist[10],int s)
{
    int i,v,min,count=1,visited[10];
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        dist[i]=cost[s][i];
    }
    visited[s]=1;
    dist[s]=0;
    while(count<n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            if(dist[i]<min&&visited[i]!=1)
            {
                min=dist[i];
                v=i;
            }
        }
        visited[v]=1;
        count++;
        for(i=1;i<=n;i++)
        {
            if(dist[v]+cost[v][i]<dist[i] && visited[i] == 0)
            dist[i]=dist[v]+cost[v][i];
        }
    }
}

void main()
{
    int i,j,s,dist[10],cost[10][10],n;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the cost matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=999;
        } 
    }
    printf("Enter the source vertex\n");
    scanf("%d",&s);
    dijk(n,cost,dist,s);
    for(i=1;i<=n;i++)
    {
        if(s!=i)
        printf("\n %d->%d=%d\n",s,i,dist[i]);
    }
} 