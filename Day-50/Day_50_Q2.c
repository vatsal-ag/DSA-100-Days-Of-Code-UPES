// You are given the root of a binary search tree (BST) and an integer val.
// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *searchBST(struct TreeNode *root, int val)
{
    if (root == NULL || root->val == val)
    {
        return root;
    }

    if (val < root->val)
    {
        return searchBST(root->left, val);
    }

    return searchBST(root->right, val);
}