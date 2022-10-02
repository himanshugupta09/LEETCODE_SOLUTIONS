class Solution {
public:
    
    long long mod = 1e9+7;
    
    int solve(int n,int k,int t,vector<vector<long long>> &dp)
    {
        if(t<0)
            return 0;
        if(n == 0 && t != 0)
            return 0;
        if(n!=0 && t == 0)
            return 0;
        if(n == 0 && t == 0)
            return 1;
        
        if(dp[n][t] != -1)
            return dp[n][t];
        
        long long ans = 0;
        
        for(int i=1;i<=k;i++)
        {
            ans = (ans%mod + solve(n-1,k,t-i, dp)%mod)%mod;
        }
        return dp[n][t] = ans;
        
    }
    
    
    
    
    int numRollsToTarget(int n, int k, int target) {
     
         vector<vector<long long>> dp(n+1, vector<long long>(target+1, -1));
        return solve(n, k, target, dp);
        
    }
};
