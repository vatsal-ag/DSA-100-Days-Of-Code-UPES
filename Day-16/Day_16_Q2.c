// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
// Name: Vatsal Agarwal
// SAP ID: 590023223

void rotate(int *nums, int numsSize, int k)
{
    if (numsSize == 0 || k % numsSize == 0) 
    {
        return; 
    }
    k = k % numsSize;
    int temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i] = nums[numsSize - k + i];
    }
    for (int i = numsSize - 1; i >= k; i--)
    {
        nums[i] = nums[i - k];
    }
    for (int i = 0; i < k; i++)
    {
        nums[i] = temp[i];
    }
}
