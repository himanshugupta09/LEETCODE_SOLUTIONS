class Solution {
public:

/* With Tabulation*/
    int solve(int n)
    {
        vector<int>dp(n+1,0);
        dp[0] = dp[1] = 1;

        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i] += dp[i-j]*dp[j-1];
            }
        }
        return dp[n];

    }
    
    int numTrees(int n) {
      
     // vector<int>memo(n+1,-1);

      return solve(n);
       
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // With Recursion Only
    int numTrees(int n) {
       if(n <= 1)
       {
           return 1;
       }
       int res = 0;

       for(int i=1;i<=n;i++)
       {
           res += numTrees(i-1)*numTrees(n-i);
       }
       return res;
       
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* With Top Down  + memoization*/
 int solve(int n,vector<int> &memo)
    {
        if(n <= 1)
        {
            return 1;
        }
        if(memo[n] != -1)
        {
            return memo[n];
        }
        int res = 0;
        for(int i=1;i<=n;i++)
        {
            res += solve(i-1,memo)*solve(n-i,memo);
        }
        return memo[n] = res;
    }
    
    int numTrees(int n) {
      
      vector<int>memo(n+1,-1);

      return solve(n,memo);
       
    }
};
