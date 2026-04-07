// Detect cycle in directed graph using DFS and recursion stack.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdbool.h>
#include <stdlib.h>

bool dfs(int u, int *head, int *next, int *to, bool *visited, bool *recStack)
{
    visited[u] = true;
    recStack[u] = true;

    for (int e = head[u]; e != -1; e = next[e])
    {
        int v = to[e];
        if (!visited[v])
        {
            if (dfs(v, head, next, to, visited, recStack))
                return true;
        }
        else if (recStack[v])
        {
            return true;
        }
    }

    recStack[u] = false;
    return false;
}

bool isCyclic(int V, int E, int edges[][2])
{
    int *head = (int *)malloc(V * sizeof(int));
    int *next = (int *)malloc(E * sizeof(int));
    int *to = (int *)malloc(E * sizeof(int));
    bool *visited = (bool *)calloc(V, sizeof(bool));
    bool *recStack = (bool *)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++)
        head[i] = -1;

    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        to[i] = v;
        next[i] = head[u];
        head[u] = i;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, head, next, to, visited, recStack))
            {
                free(head);
                free(next);
                free(to);
                free(visited);
                free(recStack);
                return true;
            }
        }
    }

    free(head);
    free(next);
    free(to);
    free(visited);
    free(recStack);
    return false;
}