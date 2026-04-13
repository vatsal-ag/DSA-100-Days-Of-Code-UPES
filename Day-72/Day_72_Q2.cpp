// Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    int n;
    int memo[1 << 20][20];
    const int INF = 1e9;

public:
    int solve(int mask, int u, vector<vector<int>>& cost) {
        if (mask == (1 << n) - 1) {
            return cost[u][0];
        }

        if (memo[mask][u] != -1) {
            return memo[mask][u];
        }

        int res = INF;

        for (int v = 0; v < n; v++) {
            if (!(mask & (1 << v))) {
                int current_cost = cost[u][v] + solve(mask | (1 << v), v, cost);
                res = min(res, current_cost);
            }
        }

        return memo[mask][u] = res;
    }

    int tsp(vector<vector<int>>& cost) {
        n = cost.size();
        if (n == 0) return 0;
        
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                memo[i][j] = -1;
            }
        }

        return solve(1, 0, cost);
    }
};