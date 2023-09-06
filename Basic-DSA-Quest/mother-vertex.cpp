//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    private:
    void dfs(int node,vector<int> &vis,int &motherVertex,vector<int> adjList[]){
        vis[node] = 1;
        for(int adjNode : adjList[node]){
            if(!vis[adjNode]) dfs(adjNode,vis,motherVertex,adjList);
        }
        motherVertex = node;
    }
public:
	int findMotherVertex(int V, vector<int>adjList[]){
	    int motherVertex = -1;
	    vector<int> vis(V,0);
	    for(int node=0;node<V;node++){
	        if(!vis[node]) dfs(node,vis,motherVertex,adjList);
	    }
	    vis = vector<int>(V,0);
	    int ans = motherVertex;
	    dfs(ans,vis,motherVertex,adjList);
	    for(int node=0;node<V;node++) if(!vis[node]) return -1;
	    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
