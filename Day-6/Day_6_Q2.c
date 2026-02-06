// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// Name: Vatsal Agarwal
// SAP ID: 590023223

void moveZeroes(int *nums, int numsSize)
{
    int j = 0; // 'j' tracks where the next non-zero number goes

    // Move all non-zeroes to the front
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            // Swap logic:
            // If we are at the same spot (no zeros found yet), this just swaps with itself.
            // If we found zeros before, this swaps the non-zero (at i) with the zero (at j).
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;

            j++; // Move the anchor forward
        }
    }
}