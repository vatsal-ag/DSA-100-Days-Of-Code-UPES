// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
// Implement the MyQueue class:
// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
    int arr[MAX_SIZE];
    int top;
} Stack;

void stackInit(Stack *s)
{
    s->top = -1;
}

void stackPush(Stack *s, int x)
{
    s->arr[++(s->top)] = x;
}

int stackPop(Stack *s)
{
    if (s->top == -1)
        return -1;
    return s->arr[(s->top)--];
}

int stackPeek(Stack *s)
{
    if (s->top == -1)
        return -1;
    return s->arr[s->top];
}

bool stackEmpty(Stack *s)
{
    return s->top == -1;
}

typedef struct
{
    Stack *stackIn;
    Stack *stackOut;
} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *obj = (MyQueue *)malloc(sizeof(MyQueue));

    obj->stackIn = (Stack *)malloc(sizeof(Stack));
    obj->stackOut = (Stack *)malloc(sizeof(Stack));

    stackInit(obj->stackIn);
    stackInit(obj->stackOut);

    return obj;
}

void myQueuePush(MyQueue *obj, int x)
{
    stackPush(obj->stackIn, x);
}

void shiftStacks(MyQueue *obj)
{
    if (stackEmpty(obj->stackOut))
    {
        while (!stackEmpty(obj->stackIn))
        {
            stackPush(obj->stackOut, stackPop(obj->stackIn));
        }
    }
}

int myQueuePop(MyQueue *obj)
{
    shiftStacks(obj);
    return stackPop(obj->stackOut);
}

int myQueuePeek(MyQueue *obj)
{
    shiftStacks(obj);
    return stackPeek(obj->stackOut);
}

bool myQueueEmpty(MyQueue *obj)
{
    return stackEmpty(obj->stackIn) && stackEmpty(obj->stackOut);
}

void myQueueFree(MyQueue *obj)
{
    free(obj->stackIn);
    free(obj->stackOut);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */
