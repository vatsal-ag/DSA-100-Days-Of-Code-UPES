// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
// Return all critical connections in the network in any order.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
    int timer = 0;
    
    void dfs(int u, int p, vector<int>& disc, vector<int>& low, 
             vector<int> adj[], vector<bool>& isArticulation) {
        
        disc[u] = low[u] = ++timer;
        int children = 0;

        for (int v : adj[u]) {
            if (v == p) continue;
            
            if (disc[v] == 0) { // v is not visited
                children++;
                dfs(v, u, disc, low, adj, isArticulation);
                low[u] = min(low[u], low[v]);

                // Check Articulation Point condition
                if (p != -1 && low[v] >= disc[u]) {
                    isArticulation[u] = true;
                }
            }
            else 
            {
                low[u] = min(low[u], disc[v]);
            }
        }
        
        if (p == -1 && children > 1) {
            isArticulation[u] = true;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> disc(V, 0), low(V, 0);
        vector<bool> isArticulation(V, false);
        vector<int> result;

        for (int i = 0; i < V; i++) {
            if (disc[i] == 0) {
                dfs(i, -1, disc, low, adj, isArticulation);
            }
        }

        for (int i = 0; i < V; i++) {
            if (isArticulation[i]) {
                result.push_back(i);
            }
        }

        if (result.empty()) return {-1};
        return result;
    }
};