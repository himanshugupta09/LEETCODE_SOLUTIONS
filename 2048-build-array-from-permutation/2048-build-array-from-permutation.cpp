class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,0);
        for(int i=0;i<n;i++)
        {
            if(nums[i] < n)
            {
                res[i] = nums[nums[i]];
            }
        }
        return res;
    }
};