//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    bool dfs(int node, int cnt, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        if (cnt == vis.size() - 1)
            if (count(vis.begin(), vis.end(), 1) == vis.size() - 1)
                return true;
        for (auto i : adj[node])
            if (!vis[i])
                if (dfs(i, cnt + 1, vis, adj))
                    return true;
        vis[node] = 0;
        return false;
    }
    bool check(int N, int M, vector<vector<int>> Edges)
    {
        // code here
        bool ans = false;

        vector<int> adj[N + 1];
        for (auto i : Edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(N + 1);

        for (int i = 1; i <= N; i++)
            ans |= dfs(i, 1, vis, adj);
        return ans;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends
