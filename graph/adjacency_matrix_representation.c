#include<stdio.h>

int main()
{
	int n,m,graph[n+1][n+1],x,y;
	printf("Enter the number of nodes and edges:\n");
	scanf("%d%d",&n,&m);
	initializeGraph(n,graph);
	printf("Enter the edges (start end):\n");
	int i,j;
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
	}
	graph[x][y]=1;
	graph[x][y]=1;
	printf("Displaying the matrix:\n");
	display(n,graph);
}
void initializeGraph(int n,int graph[][n+1])
{
    int i, j;
    for (i=0;i<n;i++)
	{
        for (j=0;j<n;j++)
		{
            graph[i][j] = 0;
        }
    }
}
void display(int n,int graph[][n+1])
{
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i=0;i<n;i++)
	{
        for (j=0;j<n;j++)
		{
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
