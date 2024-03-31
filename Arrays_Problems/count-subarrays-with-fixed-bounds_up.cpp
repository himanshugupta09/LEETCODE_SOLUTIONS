class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
       long long int res = 0;
        
        int badi=-1;
        int mini = -1;
        int maxi = -1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == maxK) maxi = i;
            if(nums[i] == minK) mini = i;
            if(nums[i] > maxK || nums[i] < minK) badi = i;
            
            res += max(0,min(maxi,mini)-badi);
        }
        return res;
    }
};
