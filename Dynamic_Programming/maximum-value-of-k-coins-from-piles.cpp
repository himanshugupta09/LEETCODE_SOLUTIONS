class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

     int n = piles.size();
     vector<vector<int>>dp(n+1,vector<int>(k+1));

     for(int i=1;i<=n;i++)
     {
         for(int j=0;j<=k;j++)
         {
            int coinSum = 0;

            for(int l=0;l<=min((int)piles[i-1].size(),j);l++)
            {
                if(l>0)
                {
                    coinSum += piles[i-1][l-1];
                }
                dp[i][j] = max(dp[i][j],dp[i-1][j-l]+coinSum);
            }
         }
     }  
     return dp[n][k];


    }
};
