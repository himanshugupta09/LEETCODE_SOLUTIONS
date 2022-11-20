class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        vector<int> dp1(nums.size(),1);
        vector<int> dp2(nums.size(),1);
        for(int i=0;i<nums.size();i++)
        {
            int x = 0;
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j])
                    x = max(x,dp1[j]);
            }
            dp1[i] += x;
        }
        int res = 0;
        for(int i=nums.size()-1;i >= 0;i--)
        {
            int x = 0;
            for(int j=nums.size()-1;j>i;j--)
            {
                if(nums[i] > nums[j])
                    x = max(x,dp2[j]);
            }
            dp2[i] += x;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(dp1[i] > 1 && dp2[i] > 1)
                res = max(res, dp1[i] + dp2[i] - 1);
        }
        return nums.size()-res;
    }
};
