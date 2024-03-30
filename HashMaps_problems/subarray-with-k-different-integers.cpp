class Solution {
public:
    int solve(vector<int>&nums,int k)
    {
         map<int,int>mp;
        int res = 0;
        
        int j = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            
            while(mp.size() > k)
            {
                
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                {
                    mp.erase(nums[j]);
                }
                j++;
            }
            res += (i-j+1);
            
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
       return solve(nums,k)-solve(nums,k-1);
        
    }
};
