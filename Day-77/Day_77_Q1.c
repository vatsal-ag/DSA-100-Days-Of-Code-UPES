// Using DFS or BFS, count number of connected components.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h>

void bfs(int start, int n, int **adj, int *adjSize, int *visited)
{
    int *queue = (int *)malloc((n + 1) * sizeof(int));
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int u = queue[front++];
        for (int i = 0; i < adjSize[u]; i++)
        {
            int v = adj[u][i];
            if (!visited[v])
            {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    free(queue);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int **adj = (int **)malloc((n + 1) * sizeof(int *));
    int *adjSize = (int *)calloc((n + 1), sizeof(int));
    int *capacity = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++)
    {
        capacity[i] = 2;
        adj[i] = (int *)malloc(capacity[i] * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        for (int j = 0; j < 2; j++)
        {
            int cur = (j == 0) ? u : v;
            int next = (j == 0) ? v : u;
            if (adjSize[cur] == capacity[cur])
            {
                capacity[cur] *= 2;
                adj[cur] = (int *)realloc(adj[cur], capacity[cur] * sizeof(int));
            }
            adj[cur][adjSize[cur]++] = next;
        }
    }

    int *visited = (int *)calloc((n + 1), sizeof(int));
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            count++;
            bfs(i, n, adj, adjSize, visited);
        }
    }

    printf("%d\n", count);

    return 0;
}