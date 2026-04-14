// In this problem, a tree is an undirected graph that is connected and has no cycles.
// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdlib.h>

int find(int *parent, int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

int *findRedundantConnection(int **edges, int edgesSize, int *edgesColSize, int *returnSize)
{
    int *parent = (int *)malloc((edgesSize + 1) * sizeof(int));
    for (int i = 0; i <= edgesSize; i++)
        parent[i] = i;

    int *result = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        int rootU = find(parent, u);
        int rootV = find(parent, v);

        if (rootU == rootV)
        {
            result[0] = u;
            result[1] = v;
            free(parent);
            return result;
        }

        parent[rootU] = rootV;
    }

    free(parent);
    return NULL;
}