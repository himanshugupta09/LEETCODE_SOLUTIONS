class Solution {
public:
    
    /*
     For this we will use Dynamic Programming Approach 
     in which we will have DP[] vector which will for knowing which station is to be used for 
     refuling 
     
     We will update our Dp array with help of stations[] given 
    
    */
    
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size();
        
        vector<long long>dp(n+1,0);
        
        // we will intialize our dp array with startFuel 
        dp[0] = startFuel;
        
        // Now we will start iterating and we will fill (i+1)th position in dp array from our           previous dp[i]
        // as dp[i+1] = max(dp[j+1],dp[j] + stations[i][1])
        
        for(int i=0;i<n;++i)
        {
            for(int j = i;j>=0;--j)
            {
                if(dp[j] >= stations[i][0])
                {
                    dp[j+1] = max(dp[j+1],(dp[j] + (long) stations[i][1]));
                    
                }
            }
        }
        
        for(int i=0;i<=n;i++)
            if(dp[i] >= target)
                return i;
        return -1;
    }
};

    
    
