#include<stdio.h> 
int ne=1, cost[10][10]; 
void main() 
{ 
  int i,j,parent[10],u,v,n,a,b,min,mincost=0; 
  printf("enter the no of vertices\n"); 
  scanf("%d",&n);    
  for(i=1;i<=n;i++) 
  { 
    parent[i]=0; 
  } 
  printf("enter the cost matrix"); 
  for(i=1;i<=n;i++) 
  { 
    for(j=1;j<=n;j++) 
    { 
      scanf("%d",&cost[i][j]);  
    } 
  } 
  while (ne<=n) 
  { 
    min=999; 
    for(i=1;i<=n;i++) 
    { 
      for(j=1;j<=n;j++) 
      { 
        if(cost[i][j]<min) 
        { 
          min=cost[i][j]; 
          a=u=i; 
          b=v=j; 
        } 
      } 
    } 
    while(parent[u]) 
    {    
      u=parent[u]; 
    } 
    while(parent[v]) 
    { 
      v=parent[v]; 
    } 
    if(u!=v) 
    { 
      printf("edge %d(%d->%d)mincost is%d\n",ne++,u,v,min); 
      mincost=mincost+min; 
      cost[a][b]=cost[b][a]=999; 
    } 
  } 
  printf("minimumcost is%d",mincost); 
} 