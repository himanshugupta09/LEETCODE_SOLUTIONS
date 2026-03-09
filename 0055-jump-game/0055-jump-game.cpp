class Solution {
public:
    // bool solve(vector<int>& nums, int pointer)
    // {
    //     if(pointer == nums.size()-1)
    //     {
    //         return true;
    //     }
    //     return solve(nums, pointer+1) && solve(nums, pointer + nums[pointer]);
    // }

    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};