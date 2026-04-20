// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
private:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited, st);
            }
        }
        st.push(u);
    }

    void dfsRev(int u, vector<vector<int>>& adjRev, vector<bool>& visited) {
        visited[u] = true;
        for (int v : adjRev[u]) {
            if (!visited[v]) {
                dfsRev(v, adjRev, visited);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>>& edges) {
        // Build actual adjacency list from edges to prevent SIGSEGV
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            if (edge.size() >= 2) {
                int u = edge[0];
                int v = edge[1];
                if (u < V && v < V) {
                    adj[u].push_back(v);
                }
            }
        }

        stack<int> st;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }

        vector<vector<int>> adjRev(V);
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                adjRev[v].push_back(u);
            }
        }

        fill(visited.begin(), visited.end(), false);
        int sccCount = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            if (!visited[u]) {
                sccCount++;
                dfsRev(u, adjRev, visited);
            }
        }

        return sccCount;
    }
};