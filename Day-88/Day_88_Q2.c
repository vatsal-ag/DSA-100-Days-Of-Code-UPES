// In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.
// Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
// Given the integer array position and the integer m. Return the required force.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int canPlaceBalls(int *position, int n, int m, int force)
{
    int ballsPlaced = 1;
    int lastPos = position[0];

    for (int i = 1; i < n; i++)
    {
        if (position[i] - lastPos >= force)
        {
            ballsPlaced++;
            lastPos = position[i];
            if (ballsPlaced >= m)
                return 1;
        }
    }
    return 0;
}

int maxDistance(int *position, int positionSize, int m)
{
    qsort(position, positionSize, sizeof(int), compare);

    int low = 1;
    int high = position[positionSize - 1] - position[0];
    int result = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canPlaceBalls(position, positionSize, m, mid))
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return result;
}

int main()
{
    int position[] = {1, 2, 3, 4, 7};
    int m = 3;
    int n = sizeof(position) / sizeof(position[0]);

    printf("Maximized minimum magnetic force: %d\n", maxDistance(position, n, m));
    return 0;
}