// A peak element is an element that is strictly greater than its neighbors.
// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
// You must write an algorithm that runs in O(log n) time.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>

int findPeakElement(int *nums, int numsSize)
{
    int low = 0;
    int high = numsSize - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] < nums[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}

int main()
{
    int nums1[] = {1, 2, 3, 1};
    printf("Peak Index: %d\n", findPeakElement(nums1, 4)); // Output: 2

    int nums2[] = {1, 2, 1, 3, 5, 6, 4};
    printf("Peak Index: %d\n", findPeakElement(nums2, 7)); // Output: 5 or 1

    return 0;
}