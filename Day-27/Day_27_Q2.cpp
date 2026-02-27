// Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution{
    public :
        void removeLoop(Node * head){

            if (head == NULL || head->next == NULL) return;

Node *slow = head;
Node *fast = head;

while (fast != NULL && fast->next != NULL)
{
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
        break;
}

if (fast == NULL || fast->next == NULL)
    return;

slow = head;

if (slow == fast)
{
    while (fast->next != slow)
        fast = fast->next;
}
else
{
    while (slow->next != fast->next)
    {

        slow = slow->next;
        fast = fast->next;
    }
}

fast->next = NULL;
}
}
;