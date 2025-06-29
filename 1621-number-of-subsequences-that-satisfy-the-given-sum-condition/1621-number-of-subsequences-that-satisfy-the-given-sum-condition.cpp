class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int m = 1e9+7;
        sort(nums.begin(),nums.end());
        int l = 0,r = nums.size()-1;
        int n = nums.size();
        vector<int>pows(n,1);

        for(int i=1;i<n;i++)
        {
            pows[i] = pows[i-1]*2%m;
        }

        int res = 0;
        while(l <= r)
        {
            if(nums[l] + nums[r] <= target)
            {
                res += pows[r-l];
                res %= m;
                l++;
            }
            else
            {
                r--;
            }
        }
        return res;

    }
};