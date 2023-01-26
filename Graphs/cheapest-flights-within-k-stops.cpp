class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>adj(n);
    // Here We have declared a vector which will store node with its neighbouring node and cost 
        for(auto e:flights)
        {
            adj[e[0]].push_back({e[1],e[2]});
        }
    
    // This Array will contain the cost calculated while operation
        vector<int>dist(n,INT_MAX);

    // Intilizing a queue for BFS Traversal
        queue<pair<int,int>>q;

        q.push({src,0});


        int stp  = 0;

        while(stp <= k && !q.empty())
        {
            int ls = q.size();

            while(ls--)
            {
                auto[node,dis] = q.front();

                q.pop();
            // Iterate over neighbors of popped node.
                for(auto& [neg,prc]:adj[node])
                {
                    if(prc + dis >= dist[neg]) continue;
                    dist[neg] = prc + dis;
                    q.push({neg,dist[neg]});

                }
            }
            stp++;
        }
        return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];
    }
};



/* 

Time Complexity : O(N + E.K)

Space Complexity : O(N + E.K)
*/
