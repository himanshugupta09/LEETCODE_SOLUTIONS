class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>prs;
        
        for(int i=0;i<heights.size();i++)
        {
            prs.push_back(heights[i]);
        }
        sort(prs.begin(),prs.end());
        
        int res = 0;
        
        for(int i=0;i<prs.size();i++)
        {
            if(heights[i] != prs[i])
            {
                res++;
            }
        }
        return res;        
    }
};
