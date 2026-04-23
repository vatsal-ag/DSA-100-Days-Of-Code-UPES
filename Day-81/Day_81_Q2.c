// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>

int search(int *nums, int numsSize, int target)
{
    int low = 0;
    int high = numsSize - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = search(nums, size, target);
    printf("Index: %d\n", result);

    return 0;
}