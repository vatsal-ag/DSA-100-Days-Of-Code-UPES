// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// Name: Vatsal Agarwal
// SAP ID: 590023223

int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
    int *ans = (int *)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        int product = 1;
        for (int j = 0; j < numsSize; j++)
        {
            if (i != j)
            {
                product *= nums[j];
            }
        }
        ans[i] = product;
    }
    return ans;
}
