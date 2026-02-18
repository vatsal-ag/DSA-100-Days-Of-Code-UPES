// Given an array of integers, rotate the array to the right by k positions.
// Name: Vatsal Agarwal
// SAP ID: 590023223

void rotate(int *nums, int numsSize, int k)
{
    int temp[numsSize];
    for (int i = 0; i < numsSize; i++)
    {
        temp[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] = temp[i];
    }
}
