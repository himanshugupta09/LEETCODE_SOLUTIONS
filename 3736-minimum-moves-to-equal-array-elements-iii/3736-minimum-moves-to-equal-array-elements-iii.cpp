class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max = *max_element(nums.begin(),nums.end());
        int res = 0;
        for(auto i:nums)
        {
            res += (max-i);
        }
        return res;
    }
};