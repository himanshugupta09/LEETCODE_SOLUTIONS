class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        int sum = amount;
        int dp[N+1][sum+1];
       for(int i=0;i<=N;i++)
       {
           dp[i][0] = 1;
       }
       for(int i=0;i<=sum;i++)
       {
           dp[0][i] = 0;
       }
       for(int i=1;i<=N;i++)
       {
           for(int j=1;j<=sum;j++)
           {
               if(coins[i-1] <= j)
               {
                   dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
               }
               else
               {
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[N][sum];
        
    }
};
