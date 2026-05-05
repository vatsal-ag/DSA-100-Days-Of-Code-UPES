// Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
// Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h>

int *relativeSortArray(int *arr1, int arr1Size, int *arr2, int arr2Size, int *returnSize)
{
    int count[1001] = {0};
    int *result = (int *)malloc(sizeof(int) * arr1Size);
    int idx = 0;

    for (int i = 0; i < arr1Size; i++)
    {
        count[arr1[i]]++;
    }

    for (int i = 0; i < arr2Size; i++)
    {
        while (count[arr2[i]] > 0)
        {
            result[idx++] = arr2[i];
            count[arr2[i]]--;
        }
    }

    for (int i = 0; i < 1001; i++)
    {
        while (count[i] > 0)
        {
            result[idx++] = i;
            count[i]--;
        }
    }

    *returnSize = arr1Size;
    return result;
}

int main()
{
    int arr1[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    int arr2[] = {2, 1, 4, 3, 9, 6};
    int returnSize;

    int *res = relativeSortArray(arr1, 11, arr2, 6, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", res[i]);
    }

    free(res);
    return 0;
}