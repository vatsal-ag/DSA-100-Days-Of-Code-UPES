// Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>

int main()
{
    int n, pos;
    // Input size
    if (scanf("%d", &n) != 1)
    {
        return 1;
    }
    int arr[n]; // Variable Length Array

    // Input array elements
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Input position to delete
    scanf("%d", &pos);

    // Shift elements to the left
    // Start at the target index (pos-1) and pull from the right
    int idx = pos - 1;
    for (int i = idx; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    // Print updated array
    // Note: Loop runs only up to n-1 because one element is gone
    for (int i = 0; i < n - 1; i++)
    {
        if (i == n - 2)
        {
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}