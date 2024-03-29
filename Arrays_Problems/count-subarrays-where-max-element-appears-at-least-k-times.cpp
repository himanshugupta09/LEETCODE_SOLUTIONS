class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxN = *max_element(nums.begin(),nums.end());
        
        int mxC = 0;
        
        int j = -1;
        long long int res = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == maxN)
            {
                mxC++;
            }
            while(mxC >= k)
            {
                res += nums.size() - i; 
                j++;
                if(nums[j] == maxN)
                {
                    mxC--;
                }
            }
            
            
        }
        return res;
    }
};
