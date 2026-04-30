// A conveyor belt has packages that must be shipped from one port to another within days days.
// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>

int canShip(int *weights, int weightsSize, int days, int capacity)
{
    int daysNeeded = 1;
    int currentLoad = 0;

    for (int i = 0; i < weightsSize; i++)
    {
        if (currentLoad + weights[i] <= capacity)
        {
            currentLoad += weights[i];
        }
        else
        {
            daysNeeded++;
            currentLoad = weights[i];
            if (daysNeeded > days)
                return 0;
        }
    }
    return 1;
}

int shipWithinDays(int *weights, int weightsSize, int days)
{
    int low = 0, high = 0;

    for (int i = 0; i < weightsSize; i++)
    {
        if (weights[i] > low)
            low = weights[i];
        high += weights[i];
    }

    int result = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canShip(weights, weightsSize, days, mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

int main()
{
    int weights[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int d = 5;

    printf("Minimum ship capacity: %d\n", shipWithinDays(weights, n, d));
    return 0;
}