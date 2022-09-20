class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        int n2 = nums1.size();
        
        int ans = 0;
        
        vector<int>row(n+1,0);
        
        vector<vector<int>>dp(n2+1,row);
        
        for(int i=0;i<n2;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(nums1[i] == nums2[j])
                {
                   if(i == 0 || j == 0)
                   {
                       dp[i][j] = 1;
                   }
                    else{
                        dp[i][j] = dp[i-1][j-1]+1;
                        
                        
                    }
                  ans = max(ans,dp[i][j]);  
                }
            }
        }
        
        
        
       
        
        return ans;
        
        
    }
};
