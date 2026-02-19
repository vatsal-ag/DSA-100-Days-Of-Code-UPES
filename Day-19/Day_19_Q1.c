// Given an array of integers, find two elements whose sum is closest to zero.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h> // Required for the abs() function

int main()
{
    int n;

    if (scanf("%d", &n) != 1)
    {
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int min_sum = 2147483647; // Maximum possible integer
    int pair1 = 0, pair2 = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            int current_sum = arr[i] + arr[j];
            if (abs(current_sum) < abs(min_sum))
            {
                min_sum = current_sum;
                pair1 = arr[i];
                pair2 = arr[j];
            }
        }
    }

    printf("%d %d\n", pair1, pair2);

    return 0;
}