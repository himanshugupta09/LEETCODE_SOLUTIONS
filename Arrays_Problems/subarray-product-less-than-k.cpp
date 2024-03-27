class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int res = 0;
        
        for(auto i:nums)
        {
            if(i < k)
            {
                res++;
            }
        }
        int n = nums.size();
        
        int i = 0;
        
        while(i < n)
        {
            int j = i+1;
            int pro = nums[i];
            while(pro < k && j < n)
            {
                pro *= nums[j];
                j++;
                if(pro < k) res++;
            }
            i++;
        }
        return res;
        
        
    }
};
