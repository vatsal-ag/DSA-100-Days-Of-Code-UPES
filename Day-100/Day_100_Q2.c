// Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int val;
    int index;
} Element;

void merge(Element *arr, int left, int mid, int right, int *count)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Element *L = (Element *)malloc(sizeof(Element) * n1);
    Element *R = (Element *)malloc(sizeof(Element) * n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int rightCount = 0;

    while (i < n1 && j < n2)
    {
        if (L[i].val <= R[j].val)
        {
            count[L[i].index] += rightCount;
            arr[k++] = L[i++];
        }
        else
        {
            rightCount++;
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        count[L[i].index] += rightCount;
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(Element *arr, int left, int right, int *count)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        merge(arr, left, mid, right, count);
    }
}

int *countSmaller(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int *count = (int *)calloc(numsSize, sizeof(int));
    Element *arr = (Element *)malloc(sizeof(Element) * numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, 0, numsSize - 1, count);

    free(arr);
    return count;
}