// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int **isConnected, int n, bool *visited, int i)
{
    for (int j = 0; j < n; j++)
    {
        if (isConnected[i][j] == 1 && !visited[j])
        {
            visited[j] = true;
            dfs(isConnected, n, visited, j);
        }
    }
}

int findCircleNum(int **isConnected, int isConnectedSize, int *isConnectedColSize)
{
    int n = isConnectedSize;
    bool *visited = (bool *)calloc(n, sizeof(bool));
    int provinceCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            provinceCount++;
            visited[i] = true;
            dfs(isConnected, n, visited, i);
        }
    }

    free(visited);
    return provinceCount;
}

int main()
{
    int n = 3;
    int *isConnected[] = {
        (int[]){1, 1, 0},
        (int[]){1, 1, 0},
        (int[]){0, 0, 1}};
    int colSize[] = {3, 3, 3};

    printf("Total Provinces: %d\n", findCircleNum(isConnected, n, colSize));

    return 0;
}