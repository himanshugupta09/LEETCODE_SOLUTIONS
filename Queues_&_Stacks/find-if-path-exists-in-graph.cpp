class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
         map<int,vector<int>>mp;

         for(auto& ed:edges)
         {
             mp[ed[0]].push_back(ed[1]);
             mp[ed[1]].push_back(ed[0]);
         }
         queue<int>q;
         q.push(source);
         vector<bool>visits(n,false);

         while(!q.empty())
         {
             int now = q.front();
             q.pop();
             if(now == destination)
             {
                 return true;
             }
             for(auto& node:mp[now])
             {
                 if(!visits[node])
                 {
                     q.push(node);
                     visits[node] = true;
                 }

             }
         }
         return false;


    }
};
