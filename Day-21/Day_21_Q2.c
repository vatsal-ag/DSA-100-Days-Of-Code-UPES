// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.
// Name: Vatsal Agarwal
// SAP ID: 590023223

/*
#include <stdio.h>
#include <stdlib.h>

struct ListNode *middleNode(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

// 1. THE FIX: Define the structure so the compiler knows what 'ListNode' means
struct ListNode
{
    int val;
    struct ListNode *next;
};

// Your original, perfectly correct function
struct ListNode *middleNode(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct ListNode *createNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    // 2. Build a test linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct ListNode *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List: 1 -> 2 -> 3 -> 4 -> 5\n");

    // 3. Call your function
    struct ListNode *middle = middleNode(head);

    // 4. Print the result to prove it works!
    if (middle != NULL)
    {
        printf("The middle node value is: %d\n", middle->val);
    }

    return 0;
}