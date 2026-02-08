// Problem: Given integers a and b, compute a^b using recursion without using pow() function.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>

power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    return a * power(a, b - 1);
}