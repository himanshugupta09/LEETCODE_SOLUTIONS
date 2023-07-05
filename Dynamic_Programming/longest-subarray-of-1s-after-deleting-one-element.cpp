class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int st = 0;
        int zc = 0;

        for(int i=0;i<n;i++)
        {
            zc += (nums[i] == 0);
            while(zc > 1)
            {
                zc -= (nums[st] == 0);
                st++;
            }
            res = max(res,i-st);
        }
        return res;
    }
};
