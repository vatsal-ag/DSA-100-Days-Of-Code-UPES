// You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.
// Name: Vatsal Agarwal
// SAP ID: 590023223

int missingNum(int *arr, int size)
{
    // Calculate the upper bound of the range (N)
    // If the array has 4 elements, the numbers are from 1 to 5.
    int n = size + 1;
    //  Calculate the Expected Sum of 1 to N
    // Formula: (n * (n + 1)) / 2
    long expectedSum = (long)n * (n + 1) / 2;

    // Actual Sum of the array elements
    long actualSum = 0;
    for (int i = 0; i < size; i++)
    {
        actualSum += arr[i];
    }

    // Return the difference
    return (int)(expectedSum - actualSum);
}
