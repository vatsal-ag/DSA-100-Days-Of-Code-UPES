// Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
// The steps of the insertion sort algorithm:
// Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
// At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
// It repeats until no input elements remain.
// The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *insertionSortList(struct ListNode *head)
{
    if (!head || !head->next)
        return head;

    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;

    struct ListNode *prev = head;
    struct ListNode *cur = head->next;

    while (cur)
    {
        if (prev->val <= cur->val)
        {
            prev = cur;
            cur = cur->next;
        }
        else
        {
            struct ListNode *temp = dummy;
            while (cur->val > temp->next->val)
            {
                temp = temp->next;
            }
            prev->next = cur->next;
            cur->next = temp->next;
            temp->next = cur;
            cur = prev->next;
        }
    }

    struct ListNode *res = dummy->next;
    free(dummy);
    return res;
}

struct ListNode *createNode(int v)
{
    struct ListNode *n = malloc(sizeof(struct ListNode));
    n->val = v;
    n->next = NULL;
    return n;
}

int main()
{
    struct ListNode *h = createNode(4);
    h->next = createNode(2);
    h->next->next = createNode(1);
    h->next->next->next = createNode(3);

    h = insertionSortList(h);

    struct ListNode *t = h;
    while (t)
    {
        printf("%d ", t->val);
        t = t->next;
    }
    return 0;
}