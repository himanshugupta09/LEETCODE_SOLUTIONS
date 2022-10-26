class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        
        mp[0] = 0;
        
        int sm = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sm += nums[i];
            
            if(mp.find(sm%k) == mp.end())
            {
                mp[sm%k] = i+1;
            }
            else if(mp[sm%k] < i)
            {
                return true;
            }
        }
        
        return false;
        
        
        
    }
};
