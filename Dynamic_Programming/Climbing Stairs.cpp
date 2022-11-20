class Solution {
public:
    
    
    int fibbo(int n,vector<int> &dp)
    {
        if(n<=2)
        {
            return n;
        }
	   if(dp[n] != -1) {
		return dp[n];
       }
	return dp[n] = fibbo(n-1,dp) + fibbo(n-2,dp);
    }
    
    
    
    
    
    
    
    
    
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        
        return fibbo(n,dp);
        
         
        
        
    }
};
