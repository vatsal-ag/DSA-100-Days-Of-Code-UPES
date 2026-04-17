// Given a reference of a node in a connected undirected graph.
// Return a deep copy (clone) of the graph.
// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
// class Node {
//     public int val;
//     public List<Node> neighbors;
// }
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdlib.h>

struct Node
{
    int val;
    int numNeighbors;
    struct Node **neighbors;
};

struct Node *visited[101];

struct Node *clone(struct Node *node)
{
    if (node == NULL)
        return NULL;

    if (visited[node->val] != NULL)
    {
        return visited[node->val];
    }

    struct Node *copy = (struct Node *)malloc(sizeof(struct Node));
    copy->val = node->val;
    copy->numNeighbors = node->numNeighbors;
    visited[node->val] = copy;

    copy->neighbors = (struct Node **)malloc(copy->numNeighbors * sizeof(struct Node *));
    for (int i = 0; i < node->numNeighbors; i++)
    {
        copy->neighbors[i] = clone(node->neighbors[i]);
    }

    return copy;
}

struct Node *cloneGraph(struct Node *node)
{
    for (int i = 0; i < 101; i++)
        visited[i] = NULL;
    return clone(node);
}