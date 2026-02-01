// Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
int main()
{
    int n, pos, x;

    scanf("%d", &n);
    int arr[n + 1]; // Size n+1 to fit the new element

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &pos); // 1-based position
    scanf("%d", &x);   // Value to insert

    // Logic: Shifting elements to the right
    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x; // Insert at index (pos-1)

    // When i is 0, 1, ... n-1: We are not at the end. Print Space.
    // When i is n: We are at the final element. Don't Print Space.
    for (int i = 0; i <= n; i++)
    {
        printf("%d", arr[i]); // Always print the number
        if (i == n)
        {
            // Do nothing (or print newline if needed)
        }
        else
        {
            printf(" "); // Print a space only if it's NOT the last element
        }
    }
    return 0;
}