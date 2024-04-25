class Solution {
public:
    
    int longestIdealString(string s, int k) {
        
        int n = s.size();
        vector<int>dp(26,0);
        int res = 0;
        for(int i=0;i<n;i++)
        {
            int cur = s[i]-'a';
            int best = 0;
            for(int j=0;j<26;j++)
            {
                if(abs(j-cur) <= k)
                {
                    
                    best = max(best,dp[j]);
                }
            }
            dp[cur] = max(dp[cur],best+1);
            res = max(res,dp[cur]);
        }
        
        return res;
    }
};
