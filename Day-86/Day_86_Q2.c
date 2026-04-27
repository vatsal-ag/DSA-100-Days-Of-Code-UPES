// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
// You must not use any built-in exponent function or operator.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>

int mySqrt(int x)
{
    if (x < 2)
    {
        return x;
    }

    int left = 1, right = x;
    int result = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid <= x / mid)
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return result;
}

int main()
{
    int x1 = 4;
    printf("Input: %d, Output: %d\n", x1, mySqrt(x1));

    int x2 = 8;
    printf("Input: %d, Output: %d\n", x2, mySqrt(x2));

    return 0;
}