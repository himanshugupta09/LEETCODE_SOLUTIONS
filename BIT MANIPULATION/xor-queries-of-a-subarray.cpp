class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        vector<int>pre(n+1,0);
        
        
        for(int i=0;i<n;i++)
        {
            pre[i+1] = (pre[i]^arr[i]);
        }
        
        vector<int>res;
        
        for(auto query:queries)
        {
            int a = query[0];
            int b = query[1];
            
            int Xor = pre[a]^pre[b+1];
            res.push_back(Xor);
            
        }
        return res;
    }
};
