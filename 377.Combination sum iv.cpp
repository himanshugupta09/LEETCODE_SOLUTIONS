/* ======================================================================================================================================================================
                                                              BRUTE FORCE APPROACH
IN THIS APPROACH WE TAKE A HELPER FUNCTION DEFINED BY THE USER WHICH CALL IT SELF RECURSIVELY AND CHECKS THE POSSIBLE COMBINATIONS FOR THE TARGET TO ACHIEVED BY THE ARRAY VALUES 
BUT DUE TO LOTS OF STACK CALLS THIS APPROACH GIVES TLE
=========================================================================================================================================================================
*/
class Solution {
public:
    int help(vector<int>& nums, int target)
    {
        if(target<0)
            return 0;
        if(target == 0)
            return 1;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            ans += help(nums,target - nums[i]);
        }
        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        return help(nums,target);
    }
};

/* ========================================================================================================================================================================
                                                                OPTIMIZED APPROACH WITH DYNAMIC PROGRAMMING TECHNIQUE
 THIS APPROACH INVOLVES USING A I-D DP ARRAY WHICH STORES ALL THE CALCULATED ANSWERS AS MEMOIZATION STEP                                                               
 ========================================================================================================================================================================
 */
 class Solution {
public:
    int help(vector<int>& nums, int target,vector<int> &dp)
    {
        if(target<0)
            return 0;
        if(target == 0)
            return 1;
        if(dp[target] != -1)
            return dp[target];
        
        
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            ans += help(nums,target - nums[i],dp);
        }
        dp[target] = ans;
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp(target+1,-1);
        return help(nums,target,dp);
    }
};
