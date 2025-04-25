class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        long long res = 0;
        mpp[0] = 1;
        int pre = 0;
        for(int i=0;i<n;i++)
        {
            pre += (nums[i]%modulo == k);
            res +=  mpp[(pre-k+modulo)%modulo];
            mpp[pre%modulo]++;
        }
        return res;
    }
};