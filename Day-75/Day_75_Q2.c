// There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:
// There are no self-edges (graph[u] does not contain u).
// There are no parallel edges (graph[u] does not contain duplicate values).
// If v is in graph[u], then u is in graph[v] (the graph is undirected).
// The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
// A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
// Return true if and only if it is bipartite.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdbool.h>
#include <string.h>

bool dfs(int u, int c, int *color, int **graph, int *graphColSize)
{
    color[u] = c;
    for (int i = 0; i < graphColSize[u]; i++)
    {
        int v = graph[u][i];
        if (color[v] == c)
            return false;
        if (color[v] == -1)
        {
            if (!dfs(v, 1 - c, color, graph, graphColSize))
                return false;
        }
    }
    return true;
}

bool isBipartite(int **graph, int graphSize, int *graphColSize)
{
    int *color = (int *)malloc(graphSize * sizeof(int));
    for (int i = 0; i < graphSize; i++)
        color[i] = -1;

    for (int i = 0; i < graphSize; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0, color, graph, graphColSize))
            {
                free(color);
                return false;
            }
        }
    }

    free(color);
    return true;
}