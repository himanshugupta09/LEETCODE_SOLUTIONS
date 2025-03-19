class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i-2] == 0)
            {
                res++;
                nums[i-2] ^= 1;
                nums[i-1] ^= 1;
                nums[i] ^= 1;
            }
        }
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum == nums.size()) return res;
        return -1;
    }
};