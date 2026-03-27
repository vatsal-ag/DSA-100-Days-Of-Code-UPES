// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Note: The returned array must be malloced, assume caller calls free().

void rightViewDFS(struct TreeNode *node, int depth, int *maxDepth, int *result, int *returnSize)
{
    if (node == NULL)
    {
        return;
    }
    if (depth > *maxDepth)
    {
        result[*returnSize] = node->val;
        (*returnSize)++;
        *maxDepth = depth;
    }
    rightViewDFS(node->right, depth + 1, maxDepth, result, returnSize);
    rightViewDFS(node->left, depth + 1, maxDepth, result, returnSize);
}

int *rightSideView(struct TreeNode *root, int *returnSize)
{
    *returnSize = 0;

    if (root == NULL)
    {
        return NULL;
    }

    int *result = (int *)malloc(100 * sizeof(int));
    int maxDepth = -1;
    rightViewDFS(root, 0, &maxDepth, result, returnSize);

    return result;
}