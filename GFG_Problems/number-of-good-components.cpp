//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        vector<bool> vis(V+1,false);
        queue<int> bfsq;
        int ans = 0;
        
        for(int i = 1; i < V + 1; i++)
        {
            if(vis[i])
            continue;
            
            int nv = 1;
            int deg = adj[i].size();
            bfsq.push(i);
            vis[i] = true;
            
            while(!bfsq.empty())
            {
                int cur_node = bfsq.front();
                bfsq.pop();
                for(auto x : adj[cur_node])
                {
                    if(!vis[x])
                    {
                        vis[x] = true;
                        bfsq.push(x);
                        nv++;
                        deg += adj[x].size();
                    }
                }
                
            }
            
    
            if(deg/2 == (nv * (nv-1))/2)
            ans++;
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends
