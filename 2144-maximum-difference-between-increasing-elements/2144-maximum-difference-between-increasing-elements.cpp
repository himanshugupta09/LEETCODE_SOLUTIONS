class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = 0;
        int mini = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            res = max(res,(nums[i]-mini));
            mini = min(mini,nums[i]);
        }
        return res==0? -1 : res;
    }
};