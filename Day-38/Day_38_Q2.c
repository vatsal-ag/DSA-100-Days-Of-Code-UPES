// You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.
// You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.
// Implement the KthLargest class:
// KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
// int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdlib.h>

typedef struct
{
    int *heap;
    int size;
    int k;
} KthLargest;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int *heap, int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent])
        {
            swap(&heap[index], &heap[parent]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void heapifyDown(int *heap, int size, int index)
{
    while (1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest])
        {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest])
        {
            smallest = right;
        }

        if (smallest != index)
        {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        }
        else
        {
            break;
        }
    }
}

int kthLargestAdd(KthLargest *obj, int val)
{
    if (obj->size < obj->k)
    {
        obj->heap[obj->size] = val;
        heapifyUp(obj->heap, obj->size);
        obj->size++;
    }
    else if (val > obj->heap[0])
    {
        obj->heap[0] = val;
        heapifyDown(obj->heap, obj->k, 0);
    }

    return obj->heap[0];
}

KthLargest *kthLargestCreate(int k, int *nums, int numsSize)
{
    KthLargest *obj = (KthLargest *)malloc(sizeof(KthLargest));
    obj->k = k;
    obj->size = 0;
    obj->heap = (int *)malloc(sizeof(int) * k);

    for (int i = 0; i < numsSize; i++)
    {
        kthLargestAdd(obj, nums[i]);
    }

    return obj;
}

void kthLargestFree(KthLargest *obj)
{
    if (obj)
    {
        free(obj->heap);
        free(obj);
    }
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 * kthLargestFree(obj);
 */