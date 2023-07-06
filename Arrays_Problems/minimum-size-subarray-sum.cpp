class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int res = INT_MAX;
        int n = nums.size();
        int sum = nums[0];

        int j = 0;

        for(int i=0;i<n;i++)
        {
            sum += nums[i];

            while(sum >= target)
            {
                res = min(res,(i-j)+1);
                sum -= nums[j];
                j++;
            }
        }
        return res == INT_MAX ? 0 : res;
        
    }
};
