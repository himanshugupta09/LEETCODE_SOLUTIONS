class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mpp;
        vector<int>res;
        unordered_map<int,int>dis_col;
        for(auto q:queries)
        {
           int ball = q[0];
           int col = q[1];
           if(mpp.find(ball) != mpp.end())
           {
                int pre = mpp[q[0]];
                dis_col[pre]--;
                if(dis_col[pre] == 0) dis_col.erase(pre);
           }
           mpp[ball] = col;
           dis_col[col]++;
           res.push_back(dis_col.size());
        }
        return res;
    }
};