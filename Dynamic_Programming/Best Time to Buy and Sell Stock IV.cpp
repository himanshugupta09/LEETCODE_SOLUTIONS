/* APPROACH WITH TABULATION WITH DP#*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int s = prices.size();
     
        vector<vector<int>>dp(s+1,vector<int>(2*k+1,0));
        
        
        
        
        for(int id = s-1;id>=0;id--)
        {
            for(int n = 2*k-1;n>=0;n--)
            {
                if(n%2 == 0)
                {
                    dp[id][n] = max(-prices[id] + dp[id+1][n+1],dp[id+1][n]);
                    
                }
                else
                {
                    dp[id][n] = max(prices[id] + dp[id+1][n+1],dp[id+1][n]);
                    
                }
            }
        }
        return dp[0][0];
        
        
        
    }
};



//===========================================      SPACE OPTIMIZED =================================================================================================//






class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int s = prices.size();
     
        vector<int>sell(2*k+1,0);
        vector<int>now(2*k+1,0);
        
        
        
        
        
        for(int id = s-1;id>=0;id--)
        {
            for(int n = 2*k-1;n>=0;n--)
            {
                if(n%2 == 0)
                {
                    now[n] = max(-prices[id] + sell[n+1],sell[n]);
                    
                }
                else
                {
                    now[n] = max(prices[id] + sell[n+1],sell[n]);
                    
                }
            }
            sell = now;
        }
        return sell[0];
        
        
        
    }
};



