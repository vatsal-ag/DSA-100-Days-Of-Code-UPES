// Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
    {
        return 1;
    }

    if (n == 0)
    {
        return 0;
    }

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // 'j' points to the last unique element found
    int j = 0;

    for (int i = 1; i < n; i++)
    {
        // If current element is different from the last unique element
        if (arr[i] != arr[j])
        {
            j++;             // Move the unique pointer forward
            arr[j] = arr[i]; // Overwrite with the new unique number
        }
    }

    // 'j' is the index, so count is j + 1
    int uniqueCount = j + 1;

    for (int i = 0; i < uniqueCount; i++)
    {
        printf("%d%s", arr[i], (i == uniqueCount - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}