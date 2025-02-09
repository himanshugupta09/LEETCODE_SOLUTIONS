class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int>mpp;
        long long res = 0;
        for(int i=0;i<nums.size();i++)
        {
            int dif = i-nums[i];
            int gp = mpp[dif];
            res += i-gp;
            mpp[dif] = gp+1;
        }
        return res;
    }
};