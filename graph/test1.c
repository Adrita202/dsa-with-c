#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];

void initializeGraph(int vertices) {
    int i, j;

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int start, int end) {
    graph[start][end] = 1;
    graph[end][start] = 1;  // Assuming an undirected graph
}

void printMatrix(int vertices) {
    int i, j;

    printf("Adjacency Matrix:\n");

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, i, start, end;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initializeGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (start end):\n");

    for (i = 0; i < edges; i++) {
        scanf("%d %d", &start, &end);
        addEdge(start, end);
    }

    printMatrix(vertices);

    return 0;
}
//#include<stdio.h>
//
//void initializeGraph(int n, int graph[][n+1])
//{
//    int i, j;
//    for (i=0;i<n;i++)
//	{
//        for (j=0;j<n;j++)
//		{
//            graph[i][j] = 0;
//        }
//    }
//}
//
//void display(int n, int graph[][n+1])
//{
//    int i, j;
//    printf("Adjacency Matrix:\n");
//    for (i=0;i<n;i++)
//	{
//        for (j=0;j<n;j++)
//		{
//            printf("%d ", graph[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//int main()
//{
//	int n,m,graph[100][100],x,y;
//	printf("Enter the number of nodes and edges:\n");
//	scanf("%d%d",&n,&m);
//	initializeGraph(n,graph);
//	printf("Enter the edges (start end):\n");
//	int i,j;
//	for(i=0;i<m;i++)
//	{
//		scanf("%d %d",&x,&y);
//		graph[x][y]=1;
//		graph[y][x]=1;
//	}
//	printf("Displaying the matrix:\n");
//	display(n,graph);
//}

