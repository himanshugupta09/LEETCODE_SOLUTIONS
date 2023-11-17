class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxSum=0;
        int n = nums.size();
        for(int i=0;i<(n/2);i++)
        {
            int cur = nums[i] + nums[n-i-1];
            maxSum = max(maxSum,cur);
        }
        return maxSum;
        
    }
};
