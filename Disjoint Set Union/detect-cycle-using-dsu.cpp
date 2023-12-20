//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    
    vector<int>par;
    vector<int>rank;
    
    int find_set(int x,vector<int>&par)
    {
        if(par[x] == x)
        {
            return x;
        }
        return par[x] = find_set(par[x],par);
    }
    void Union(int x,int y,vector<int>&par,vector<int>&rank)
    {
        int a = find_set(x,par);
        int b = find_set(y,par);
        
        int n1 = rank[a];
        int n2 = rank[b];
        
        if(a != b)
        {
            if(n1 < n2)
            {
                swap(a,b);
            }
            par[b] = a;
            rank[a]+=rank[b];
        }
    }
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    par.resize(V);
	    rank.resize(V,1);
	    for(int i=0;i<V;i++)
	    {
	        par[i]=i;
	    }
	    
	    bool cycle =  0;
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto node:adj[i])
	        {
	            if (find_set(i, par) == find_set(node, par) && i < node)
	            {
	                return 1;
	            }
	            Union(i,node,par,rank);
	        }
	    }
	    
	    return 0;
	    
	    
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
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends
