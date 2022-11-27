class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
     
        int m   = multipliers.size();
        int n = nums.size();
        
        vector<int>dp(m+1,0);
        
        for(int i=m-1;i>=0;i--)
        {
            vector<int>temp(dp);
            for(int j = i;j>=0;j--)
            {
                dp[j]  = max(multipliers[i]*nums[j] + temp[j+1], multipliers[i]*nums[n-1-(i-j)] + temp[j]);
                
            }
        }
        
        return dp[0];
        
        
    }
};
