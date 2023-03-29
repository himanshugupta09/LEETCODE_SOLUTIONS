class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j] = max(satisfaction[i]*j + dp[i+1][j+1],dp[i+1][j]);
            }
        }

        return dp[0][1];
    }
};
