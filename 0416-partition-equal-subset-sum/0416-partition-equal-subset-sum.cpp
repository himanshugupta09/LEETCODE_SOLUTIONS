class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int target = totalSum/2;
        if(totalSum%2)
        {
            return false;
        }
        vector<bool> dp(target + 1, false);  // corrected
        dp[0] = true;

        for(int num:nums)
        {
            for(int w = target;w > num-1;w--)
            {
                if(dp[w-num])
                {
                    dp[w] = true;
                }
            }
        }
        return dp[target];
    }
};