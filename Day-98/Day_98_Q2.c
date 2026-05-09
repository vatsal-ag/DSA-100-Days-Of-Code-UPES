// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h>

int compareIntervals(const void *a, const void *b)
{
    int *intervalA = *(int **)a;
    int *intervalB = *(int **)b;
    return intervalA[0] - intervalB[0];
}

int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes)
{
    if (intervalsSize <= 0)
    {
        *returnSize = 0;
        return NULL;
    }

    qsort(intervals, intervalsSize, sizeof(int *), compareIntervals);

    int **merged = (int **)malloc(sizeof(int *) * intervalsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * intervalsSize);

    int count = 0;
    int *current = (int *)malloc(sizeof(int) * 2);
    current[0] = intervals[0][0];
    current[1] = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++)
    {
        if (intervals[i][0] <= current[1])
        {
            if (intervals[i][1] > current[1])
            {
                current[1] = intervals[i][1];
            }
        }
        else
        {
            merged[count] = current;
            (*returnColumnSizes)[count] = 2;
            count++;

            current = (int *)malloc(sizeof(int) * 2);
            current[0] = intervals[i][0];
            current[1] = intervals[i][1];
        }
    }

    merged[count] = current;
    (*returnColumnSizes)[count] = 2;
    count++;

    *returnSize = count;
    return merged;
}