class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
       unordered_map<int,int>up;
       unordered_set<int>seen;

       for(auto & match:matches)
       {
           int w = match[0],los = match[1];
           seen.insert(w);
           seen.insert(los);
           up[los]++;

       }

       vector<vector<int>>res(2,vector<int>());

       for(auto p:seen)
       {
           if(up.find(p) == up.end())
           {
               res[0].push_back(p);
           }
           else if(up[p] == 1)
           {
               res[1].push_back(p);
           }
       }

       sort(res[0].begin(),res[0].end());
       sort(res[1].begin(),res[1].end());

       return res;
       
    }
};
