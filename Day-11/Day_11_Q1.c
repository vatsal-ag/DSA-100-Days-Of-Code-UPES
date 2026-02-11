// Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>

int main()
{
    int m, n;

    if (scanf("%d %d", &m, &n) != 2)
        return 1;

    int A[m][n], B[m][n], sum[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d%s", sum[i][j], (j == n - 1) ? "" : " ");
        }
        printf("\n");
    }

    return 0;
}