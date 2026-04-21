// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000

int findTheCity(int n, int **edges, int edgesSize, int *edgesColSize, int distanceThreshold)
{
    int dist[n][n];
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    for (i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if (u < n && v < n)
        {
            dist[u][v] = w;
            dist[v][u] = w;
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int minReachable = n;
    int resultCity = -1;

    for (i = 0; i < n; i++)
    {
        int reachableCount = 0;
        for (j = 0; j < n; j++)
        {
            if (i != j && dist[i][j] <= distanceThreshold)
            {
                reachableCount++;
            }
        }

        if (reachableCount <= minReachable)
        {
            minReachable = reachableCount;
            resultCity = i;
        }
    }

    return resultCity;
}