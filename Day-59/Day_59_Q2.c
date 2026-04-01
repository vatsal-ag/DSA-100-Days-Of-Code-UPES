// You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
// Return the minimum number of cameras needed to monitor all nodes of the tree.
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

int cameraCount;

int solve(struct TreeNode *node)
{
    if (node == NULL)
    {
        return 2;
    }

    int left = solve(node->left);
    int right = solve(node->right);

    if (left == 0 || right == 0)
    {
        cameraCount++;
        return 1;
    }

    if (left == 1 || right == 1)
    {
        return 2;
    }

    return 0;
}

int minCameraCover(struct TreeNode *root)
{
    cameraCount = 0;

    if (solve(root) == 0)
    {
        cameraCount++;
    }

    return cameraCount;
}

// 0: Node is not covered
// 1: Node has a camera
// 2: Node is covered by a camera elsewhere