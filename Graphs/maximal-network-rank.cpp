class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
       unordered_map<int,unordered_set<int>>mp;

       for(auto i:roads)
       {
           mp[i[0]].insert(i[1]);
           mp[i[1]].insert(i[0]);
       }
       int maxRank = 0;

       for(int node1 = 0;node1 < n;node1++)
       {
           for(int node2 = node1+1;node2 < n;node2++)
           {
               int curRank = mp[node1].size() + mp[node2].size();
               if(mp[node1].find(node2) != mp[node1].end())
               {
                   curRank--;
               }
               maxRank = max(maxRank,curRank);
           }

       }
       return maxRank;


    }
};
