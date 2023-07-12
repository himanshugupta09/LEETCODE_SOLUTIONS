class Solution {
public:

    // vector<int>eS(vector<vector<int>>& g)
    // {
    //     int n = g.size();
    //     vector<int>inD(n);
    //     vector<vector<int>>ad(n);

    //     for(int i=0;i<n;i++)
    //     {
    //         for(auto node:g[i])
    //         {
    //             ad[node].push_back(i);
    //             inD[i]++;
    //         }
    //     }
    //     queue<int>q;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(inD[i] == 0)
    //         {
    //             q.push(i);
    //         }
    //     }
    //     vector<bool>sf(n);

    //     while(!q.empty())
    //     {
    //         int no = q.front();
    //         q.pop();

    //         sf[no] = true;

    //         for(auto& neigh: ad[no])
    //         {
    //             inD[neigh]--;
    //             if(inD[neigh] == 0)
    //             {
    //                 q.push(neigh);
    //             }
    //         }
    //     }

    //     vector<int>safen;

    //     for(int i=0;i<n;i++)
    //     {
    //         if(sf[i])
    //         {
    //             safen.push_back(i);
    //         }
    //     }
    //     return safen;
    // }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>inD(n);
        vector<vector<int>>ad(n);

        for(int i=0;i<n;i++)
        {
            for(auto node:graph[i])
            {
                ad[node].push_back(i);
                inD[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(inD[i] == 0)
            {
                q.push(i);
            }
        }
        vector<bool>sf(n);

        while(!q.empty())
        {
            int no = q.front();
            q.pop();

            sf[no] = true;

            for(auto& neigh: ad[no])
            {
                inD[neigh]--;
                if(inD[neigh] == 0)
                {
                    q.push(neigh);
                }
            }
        }

        vector<int>safen;

        for(int i=0;i<n;i++)
        {
            if(sf[i])
            {
                safen.push_back(i);
            }
        }
        return safen;
    }
};
