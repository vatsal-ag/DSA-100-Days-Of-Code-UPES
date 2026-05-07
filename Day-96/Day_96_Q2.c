// Given an integer array nums, return the number of reverse pairs in the array.
// A reverse pair is a pair (i, j) where:
// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h>

int mergeAndCount(int *nums, int low, int mid, int high)
{
    int count = 0;
    int j = mid + 1;

    for (int i = low; i <= mid; i++)
    {
        while (j <= high && (long)nums[i] > 2 * (long)nums[j])
        {
            j++;
        }
        count += (j - (mid + 1));
    }

    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = nums[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = nums[mid + 1 + j];

    int i = 0, k = low;
    j = 0;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            nums[k++] = L[i++];
        }
        else
        {
            nums[k++] = R[j++];
        }
    }

    while (i < n1)
        nums[k++] = L[i++];
    while (j < n2)
        nums[k++] = R[j++];

    return count;
}

int reversePairsRecursive(int *nums, int low, int high)
{
    if (low >= high)
        return 0;

    int mid = low + (high - low) / 2;
    int count = reversePairsRecursive(nums, low, mid);
    count += reversePairsRecursive(nums, mid + 1, high);
    count += mergeAndCount(nums, low, mid, high);

    return count;
}

int reversePairs(int *nums, int numsSize)
{
    return reversePairsRecursive(nums, 0, numsSize - 1);
}

int main()
{
    int nums1[] = {1, 3, 2, 3, 1};
    printf("Example 1 Output: %d\n", reversePairs(nums1, 5));

    int nums2[] = {2, 4, 3, 5, 1};
    printf("Example 2 Output: %d\n", reversePairs(nums2, 5));

    return 0;
}