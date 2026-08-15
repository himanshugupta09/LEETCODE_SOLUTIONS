class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        if(count(nums.begin(),nums.end(),0) == nums.size())
        {
            return 0;
        }
        int totalXor = 0;
        for(auto i:nums)
        {
            totalXor ^= i;
        }
        if(totalXor != 0)
        {
            return nums.size();
        }
        
        return nums.size()-1;
    }
};