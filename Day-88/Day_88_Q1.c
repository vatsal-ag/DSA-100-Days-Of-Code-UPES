// Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int canPlaceCows(int *stalls, int n, int k, int dist)
{
    int cowsPlaced = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - lastPosition >= dist)
        {
            cowsPlaced++;
            lastPosition = stalls[i];
            if (cowsPlaced >= k)
                return 1;
        }
    }
    return 0;
}

int solve()
{
    int n, k;
    if (scanf("%d %d", &n, &k) != 2)
        return 0;

    int *stalls = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stalls[i]);
    }

    // Binary search requires sorted stalls
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int result = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, n, k, mid))
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("%d\n", result);
    free(stalls);
    return 0;
}

int main()
{
    solve();
    return 0;
}
