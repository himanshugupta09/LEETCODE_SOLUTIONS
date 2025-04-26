class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int lmin =  -1;
        int lmax = -1;
        int n = nums.size();
        int j=-1;
        long long res = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == minK)
            {
                lmin = i;
            }
            if(nums[i] == maxK)
            {
                lmax = i;
            }
            if(nums[i] > maxK || nums[i] < minK)
            {
                j = i;
            }
            res += max(0,min(lmax,lmin)-j);
        }
        return res;
    }
};