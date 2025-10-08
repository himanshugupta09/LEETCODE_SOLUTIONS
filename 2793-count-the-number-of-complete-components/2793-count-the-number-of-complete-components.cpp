class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, 
             int& nodeCount, int& edgeCount) {
        vis[node] = true;
        nodeCount++;
        edgeCount += adj[node].size();  // Count all edges from this node

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(neigh, adj, vis, nodeCount, edgeCount);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);  // Undirected graph
        }

        vector<bool> vis(n, false);
        int completeCount = 0;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                int nodeCount = 0;
                int edgeCount = 0;

                dfs(i, adj, vis, nodeCount, edgeCount);

                // Each undirected edge is counted twice in edgeCount
                edgeCount /= 2;

                if (edgeCount == nodeCount * (nodeCount - 1) / 2) {
                    completeCount++;
                }
            }
        }

        return completeCount;
    }
};
