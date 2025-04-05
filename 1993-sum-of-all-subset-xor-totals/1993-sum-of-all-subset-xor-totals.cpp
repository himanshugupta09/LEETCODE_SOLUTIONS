class Solution {
public:
    void generateSubsets(vector<int>&nums,int idx,vector<int>&a,vector<vector<int>>&subs)
    {
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        for(int num:nums)
        {
            res |= num;
        }
        return res << (nums.size()-1);
    }
};