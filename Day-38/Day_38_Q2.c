// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
// Return the max sliding window.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize)
{

    if (numsSize == 0 || k == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize - k + 1;
    int *result = (int *)malloc(sizeof(int) * (*returnSize));

    int *deque = (int *)malloc(sizeof(int) * numsSize);
    int front = 0;
    int rear = -1;

    for (int i = 0; i < numsSize; i++)
    {

        if (front <= rear && deque[front] < i - k + 1)
        {
            front++;
        }

        while (front <= rear && nums[deque[rear]] <= nums[i])
        {
            rear--;
        }

        deque[++rear] = i;

        if (i >= k - 1)
        {
            result[i - k + 1] = nums[deque[front]];
        }
    }

    free(deque);

    return result;
}