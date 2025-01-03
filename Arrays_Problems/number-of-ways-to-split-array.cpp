class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        // vector<int>prefixSum(n+1,0);
        // vector<int>backs(n,0);
        // backs[n-1] = nums[n-1];
        // prefixSum[0] = nums[0];
        // for(int i=1;i<n;i++)
        // {
        //     prefixSum[i] =  prefixSum[i-1]+nums[i];
        // }
        // for(int i=n-2;i>=0;i--)
        // {
        //     backs[i] = backs[i+1]+nums[i];
        // }
        long long int  total =0;
        int res = 0;
        long long int curSum=0;
        for(int i:nums)
        {
            total += i;
        }
        for(int i=0;i<n-1;i++)
        {
           curSum += nums[i];
            total-=nums[i];
           if(curSum >= total)
           {
             res++;
           }
        }
        return res;

    }
};
