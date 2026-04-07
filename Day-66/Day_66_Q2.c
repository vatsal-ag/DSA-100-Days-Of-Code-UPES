// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdbool.h>
#include <stdlib.h>

bool hasCycle(int u, int *head, int *next, int *to, bool *visited, bool *pathStack)
{
    visited[u] = true;
    pathStack[u] = true;

    for (int e = head[u]; e != -1; e = next[e])
    {
        int v = to[e];
        if (!visited[v])
        {
            if (hasCycle(v, head, next, to, visited, pathStack))
                return true;
        }
        else if (pathStack[v])
        {
            return true;
        }
    }

    pathStack[u] = false;
    return false;
}

bool canFinish(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize)
{
    if (numCourses <= 0)
        return true;

    int *head = (int *)malloc(numCourses * sizeof(int));
    int *next = (int *)malloc(prerequisitesSize * sizeof(int));
    int *to = (int *)malloc(prerequisitesSize * sizeof(int));

    for (int i = 0; i < numCourses; i++)
        head[i] = -1;

    for (int i = 0; i < prerequisitesSize; i++)
    {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        to[i] = a;
        next[i] = head[b];
        head[b] = i;
    }

    bool *visited = (bool *)calloc(numCourses, sizeof(bool));
    bool *pathStack = (bool *)calloc(numCourses, sizeof(bool));

    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i])
        {
            if (hasCycle(i, head, next, to, visited, pathStack))
            {
                // Cycle found, cleanup and return false
                free(head);
                free(next);
                free(to);
                free(visited);
                free(pathStack);
                return false;
            }
        }
    }

    free(head);
    free(next);
    free(to);
    free(visited);
    free(pathStack);
    return true;
}
