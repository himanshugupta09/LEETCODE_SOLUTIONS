class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        int idx = 0,max_cnt = 0;
        
        for(int i=0;i<mat.size();i++)
        {
            int cnt = count(mat[i].begin(),mat[i].end(),1);
            if(cnt > max_cnt)
            {
                idx = i;
                max_cnt = cnt;
            }
            
        }
        return {idx,max_cnt};
        
    }
};
