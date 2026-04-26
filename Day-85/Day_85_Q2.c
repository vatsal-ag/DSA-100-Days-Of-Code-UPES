// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
// Given the sorted rotated array nums of unique elements, return the minimum element of this array.
// You must write an algorithm that runs in O(log n) time.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>

int findMin(int *nums, int numsSize)
{
    int left = 0;
    int right = numsSize - 1;

    if (nums[left] <= nums[right])
    {
        return nums[left];
    }

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return nums[left];
}

int main()
{
    int nums1[] = {3, 4, 5, 1, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Minimum: %d\n", findMin(nums1, size1));

    int nums2[] = {4, 5, 6, 7, 0, 1, 2};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Minimum: %d\n", findMin(nums2, size2));

    return 0;
}