class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int f = INT_MAX,s = INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            if(s < nums[i])
            {
                return true;
            }
            if(nums[i] <= f)
            {
                f = nums[i];
            }
            else{
                s = nums[i];
                
            }
        }
        return false;
        
    }
};
