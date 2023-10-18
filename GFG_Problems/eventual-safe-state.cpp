//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<bool>vis;
    vector<bool>ok;
    
    bool help(int node,vector<int>adj[])
    {
        if(ok[node])
        {
            return true;
        }
        if(vis[node])
        {
            return false;
        }
        vis[node] = true;
        bool res = true;
        for(auto i:adj[node])
        {
            res = res&help(i,adj);
        }
        return ok[node] = res;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vis.assign(V,false);
        ok.assign(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                help(i,adj);
            }
        }
        vector<int>res;
        
        for(int i=0;i<V;i++)
        {
            if(ok[i])
            {
                res.push_back(i);
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
