class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        set<int>uni(nums.begin(),nums.end());
        int res = 0;
        int n = nums.size();
        int k = uni.size();
        unordered_map<int,int>mp;
        int j = 0;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] == 1) k--;

            while(k == 0)
            {
                mp[nums[j]]--;
                if(mp[nums[j++]] == 0) k++;
            }
            res += j;
        }
        return res;
        
    }
};