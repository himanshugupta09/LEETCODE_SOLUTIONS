class Solution {
public:
    bool isGood(vector<int>& nums) {
        int base = nums.size()-1;

        unordered_map<int,int>mp;

        for(auto i:nums)
        {
            if(i > base)
            {
                return false;
            }
            mp[i]++;
            if(i != base && mp[i]>1)
            {
                return false;
            }
        }
        if(mp[base]>2)
        {
            return false;
        }
        return true;
    }
};
