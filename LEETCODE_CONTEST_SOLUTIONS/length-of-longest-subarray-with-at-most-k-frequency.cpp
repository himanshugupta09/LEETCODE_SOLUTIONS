class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        int maxLen = -1;
        int n = nums.size();
        int str = -1;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            
            while(mp[nums[i]] > k)
            {
                str++;
                mp[nums[str]]--;
            }
            maxLen = max(maxLen,(i-str));
        }
        return maxLen;
    }
};
