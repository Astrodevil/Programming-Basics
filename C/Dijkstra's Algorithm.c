#include<stdio.h>
int d[5],parent[5],vcount;
int G[5][5]={{999,10,999,5,999},{999,999,1,2,999},{999,999,999,999,4},{999,3,9,999,2},{7,999,6,999,999}};
void DIJKSTRA(int);
void INITIALIZE_SINGLE_SOURCE(int);
void RELAX(int u,int v);
int EXTRACT_MIN(int *);
void PrintPath(int,int);
int main()
{
	int i,j,src,dest;
	printf("Enter the no of vertices in the graph:");
	scanf("%d",&vcount);

	printf("Enter the source no to start: ");
	scanf("%d",&src);
	DIJKSTRA(src);
	for(i=0;i<vcount;i++)
	{
		printf("Parent of %d=%d\n",i,parent[i]);
	}
	printf("Enter the destination vertex:");
	scanf("%d",&dest);
	printf("Cost to travel from %d to %d is %d.\n",src,dest,d[dest]);
	printf("Path: ");
    PrintPath(src,dest);
	return 0;
}
void DIJKSTRA(int src)
{
	int i,vc=vcount,u,Q[5];
	INITIALIZE_SINGLE_SOURCE(src);
	for(i=0;i<vcount;i++)
		Q[i]=0;
	while(vc!=0)
	{
        int u = EXTRACT_MIN(Q);
		for(i=0;i<vcount;i++)
        {
            if(G[u][i]!=999)
            {
                RELAX(u,i);
            }
        }
		vc--;
	}
}
void INITIALIZE_SINGLE_SOURCE(int src)
{
	int i;
	for(i=0;i<vcount;i++)
	{
        d[i]=999;
        parent[i]=-1;
	}
	d[src]= 0;
}
void RELAX(int u,int v)
{
	if(d[v]>d[u]+G[u][v])
	{
        d[v]=d[u]+G[u][v];
        parent[v] = u;
	}
}
int EXTRACT_MIN(int *p)
{
	int i,min=999,x;
		for(i=0;i<vcount;i++)
		{
            if(*(p+i)==0)
            {
                if(d[i]<min)
                {
                    min=d[i];
                    x=i;
                }
            }
		}
    *(p+x)=1;
	return x;
}
void PrintPath(int s,int v)
{
    if(v==s)
        printf("%d ",s);
    else if(parent[v]==-1)
        printf("No path from %d to %d",s,v);
    else
    {
        PrintPath(s,parent[v]);
        printf("%d ",v);
    }
}
