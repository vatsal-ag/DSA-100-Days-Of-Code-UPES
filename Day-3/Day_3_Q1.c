// Implement linear search to find key k in an array. Count and display the number of comparisons performed.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>

int main()
{
    int n, k;
    int found = 0; // 0 = False, 1 = True
    int comparisons = 0;

    // Input size
    if (scanf("%d", &n) != 1)
    {
        return 1;
    }

    // Input array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    scanf("%d", &k);

    // Linear Search
    for (int i = 0; i < n; i++)
    {
        comparisons++; // Count this attempt

        if (arr[i] == k)
        {
            printf("Found at index %d\n", i);
            found = 1; // Mark success
            break;     // Stop searching!
        }
    }

    if (!found)
    {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", comparisons);

    return 0;
}