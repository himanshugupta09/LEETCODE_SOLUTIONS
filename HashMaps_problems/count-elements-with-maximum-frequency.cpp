class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        map<int,int>mp;
        int mx = INT_MIN;
        
        for(auto i:nums)
        {
            mp[i]++;
            mx = max(mx,mp[i]);
        }
        int res = 0;
        
        for(auto i:mp)
        {
            if(i.second == mx)
            {
                res += i.second;
            }
        }
        return res;
        
    }
};
