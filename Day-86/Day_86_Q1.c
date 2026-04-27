// Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>

int find_square_root(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    int left = 1, right = n, answer = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (mid <= n / mid)
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return answer;
}

int main()
{
    int n;

    if (scanf("%d", &n) == 1)
    {
        if (n < 0)
        {
            printf("Invalid input\n");
        }
        else
        {
            printf("%d\n", find_square_root(n));
        }
    }

    return 0;
}