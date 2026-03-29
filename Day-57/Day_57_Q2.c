// Given the root of a binary tree, flatten the tree into a "linked list":
// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.
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

void flatten(struct TreeNode *root)
{
    struct TreeNode *current = root;

    while (current != NULL)
    {
        if (current->left != NULL)
        {

            struct TreeNode *runner = current->left;
            while (runner->right != NULL)
            {
                runner = runner->right;
            }

            runner->right = current->right;

            current->right = current->left;

            current->left = NULL;
        }

        current = current->right;
    }
}