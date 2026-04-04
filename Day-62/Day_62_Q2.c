// There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
// When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.
// Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdbool.h>
#include <stdlib.h>

bool canVisitAllRooms(int **rooms, int roomsSize, int *roomsColSize)
{
    bool *visited = (bool *)calloc(roomsSize, sizeof(bool));
    int visitedCount = 0;

    int *stack = (int *)malloc(roomsSize * sizeof(int));
    int top = -1;

    stack[++top] = 0;
    visited[0] = true;
    visitedCount++;

    while (top >= 0)
    {
        int currentRoom = stack[top--];

        for (int i = 0; i < roomsColSize[currentRoom]; i++)
        {
            int key = rooms[currentRoom][i];

            if (!visited[key])
            {
                visited[key] = true;
                visitedCount++;
                stack[++top] = key;

                if (visitedCount == roomsSize)
                {
                    free(visited);
                    free(stack);
                    return true;
                }
            }
        }
    }

    bool result = (visitedCount == roomsSize);
    free(visited);
    free(stack);
    return result;
}