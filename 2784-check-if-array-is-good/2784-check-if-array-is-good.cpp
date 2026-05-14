class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int base = nums.size()-1;

        for(int i:nums)
        {
            if(i > base)
            {
                return false;
            }
            mpp[i]++;
            if(i != base && mpp[i]>1)
            {
                return false;
            }
        }
        if(mpp[base] > 2) return false;
        return true;
    }
};