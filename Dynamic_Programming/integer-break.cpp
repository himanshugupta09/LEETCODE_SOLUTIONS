class Solution {
public:
/* 
This is the Bottom up Approach for the problem using tabulation method*/
    int integerBreak(int n) {
        int ans = 1;

        if(n == 1 || n == 2)
        {
            return 1;
        }
        if(n == 3)
        {
            return 2;
        }
        else
        {
            vector<int>dp(n+1,-1);
            dp[1] = 1;
            
            for(int i=2;i<=n;i++)
            {
                for(int j=1;j<i;j++)
                {
                    dp[i] = max(dp[i], (max(j,dp[j])) * (max(i - j, dp[i - j])));
                }
            }


            return dp[n];
            


        }

    }
};
