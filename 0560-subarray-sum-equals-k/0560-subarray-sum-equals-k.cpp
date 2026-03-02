class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int>mpp;
        int curSum = 0;
        mpp[curSum] = 1;
        
        for(int i=0;i<nums.size();i++)
        {
            curSum += nums[i];
            int dif = curSum - k;
            if(mpp.find(dif) != mpp.end())
            {
                count += mpp[dif];
            }
            mpp[curSum]++;

        }
        return count;
    }
};



