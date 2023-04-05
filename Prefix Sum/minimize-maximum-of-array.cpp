class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n  = nums.size();
        long long res = 0,ps = 0;

        for(int i=0;i<n;i++)
        {
            ps += nums[i];
            res = max(res,(ps+i)/(i+1));
        }
        
        return res;
    }
};
