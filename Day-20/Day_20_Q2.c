// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdlib.h>

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (numsSize < 3)
        return NULL;
    for (int i = 0; i < numsSize - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[j] < nums[min_idx])
            {
                min_idx = j;
            }
        }

        int temp = nums[i];
        nums[i] = nums[min_idx];
        nums[min_idx] = temp;
    }

    int capacity = 1000;
    int **result = (int **)malloc(capacity * sizeof(int *));
    *returnColumnSizes = (int *)malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++)
    {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                if (*returnSize >= capacity)
                {
                    capacity *= 2;
                    result = (int **)realloc(result, capacity * sizeof(int *));
                    *returnColumnSizes = (int *)realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                result[*returnSize] = (int *)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return result;
}
