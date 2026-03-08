// Design your implementation of the circular double-ended queue (deque).
// Implement the MyCircularDeque class:
// MyCircularDeque(int k) Initializes the deque with a maximum size of k.
// boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
// boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
// boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
// boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
// int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
// int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
// boolean isEmpty() Returns true if the deque is empty, or false otherwise.
// boolean isFull() Returns true if the deque is full, or false otherwise.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;

bool myCircularDequeIsEmpty(MyCircularDeque *obj)
{
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque *obj)
{
    return obj->size == obj->capacity;
}

MyCircularDeque *myCircularDequeCreate(int k)
{
    MyCircularDeque *obj = (MyCircularDeque *)malloc(sizeof(MyCircularDeque));
    obj->capacity = k;
    obj->size = 0;
    obj->arr = (int *)malloc(sizeof(int) * k);

    obj->front = 0;
    obj->rear = k - 1;

    return obj;
}

bool myCircularDequeInsertFront(MyCircularDeque *obj, int value)
{
    if (myCircularDequeIsFull(obj))
        return false;

    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->arr[obj->front] = value;
    obj->size++;

    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque *obj, int value)
{
    if (myCircularDequeIsFull(obj))
        return false;

    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->arr[obj->rear] = value;
    obj->size++;

    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque *obj)
{
    if (myCircularDequeIsEmpty(obj))
        return false;

    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;

    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque *obj)
{
    if (myCircularDequeIsEmpty(obj))
        return false;

    obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    obj->size--;

    return true;
}

int myCircularDequeGetFront(MyCircularDeque *obj)
{
    if (myCircularDequeIsEmpty(obj))
        return -1;
    return obj->arr[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque *obj)
{
    if (myCircularDequeIsEmpty(obj))
        return -1;
    return obj->arr[obj->rear];
}

void myCircularDequeFree(MyCircularDeque *obj)
{
    free(obj->arr);
    free(obj);
}
