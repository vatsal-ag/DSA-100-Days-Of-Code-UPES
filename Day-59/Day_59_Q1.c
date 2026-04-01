// Check whether a given binary tree satisfies the Min-Heap property.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

int countNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    return (1 + countNodes(root->left) + countNodes(root->right));
}

// Check if the tree is a Complete Binary Tree
bool isComplete(struct Node *root, int index, int node_count)
{
    if (root == NULL)
        return true;
    if (index >= node_count)
        return false;

    return (isComplete(root->left, 2 * index + 1, node_count) &&
            isComplete(root->right, 2 * index + 2, node_count));
}

bool checkMinHeapProperty(struct Node *root)
{
    if (root->left == NULL && root->right == NULL)
        return true;

    if (root->right == NULL)
    {
        return root->data <= root->left->data;
    }
    else
    {
        if (root->data <= root->left->data && root->data <= root->right->data)
        {
            return checkMinHeapProperty(root->left) && checkMinHeapProperty(root->right);
        }
        else
        {
            return false;
        }
    }
}

bool isMinHeap(struct Node *root)
{
    int node_count = countNodes(root);
    int index = 0;

    if (isComplete(root, index, node_count) && checkMinHeapProperty(root))
    {
        return true;
    }
    return false;
}