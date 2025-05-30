class Solution {
public:
    void dfs(int node,vector<int>&dis_node,vector<bool>&vis,vector<int>&edges,int dis)
    {
        if(node!=-1 && !vis[node] )
           {  vis[node] = true;
              dis_node[node] = dis;
             dfs(edges[node], dis_node, vis, edges, dis+1);
           }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
       int n = edges.size();
        vector<int>nodes1_dist(n,-1);
        vector<int>nodes2_dist(n,-1);
        vector<bool>vis(n,false);
        dfs(node1,nodes1_dist,vis,edges,0);
        vis.assign(n,false);
        dfs(node2,nodes2_dist,vis,edges,0);
        int res = -1;
        int answer = n;
        for(int i=0;i<n;i++)
        {
            if(nodes1_dist[i] != -1 && nodes2_dist[i] != -1)
            {
                if(max(nodes1_dist[i],nodes2_dist[i]) < answer)
                {
                    answer = max(nodes1_dist[i],nodes2_dist[i]);
                    res = i;
                }
            }
        }
        return res;

    }
};