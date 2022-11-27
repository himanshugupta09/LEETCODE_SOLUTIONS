class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
       unordered_map<int,int>m;
        
        
       int cnt = 0;
        
        if(nums.size() == 1 && nums[0]%k != 0)
        {
            return cnt;
            
        }
        
        //vector<int>sums(nums.size()),0);
        //sums[0] = nums[0];
        
        int sm = 0;
        
        m[0] = 1;
        
        for(int i=0;i<nums.size();i++)
        {
            sm = (sm + nums[i])%k;
            if(sm<0) sm+=k;
            
            cnt += m[sm];
            m[sm]++;
            
            
        }
        
        return cnt;
        
        
    }
};
