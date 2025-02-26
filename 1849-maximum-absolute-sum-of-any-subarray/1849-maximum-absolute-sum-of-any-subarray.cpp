class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxS =  INT_MIN;
        int minS = INT_MAX;
        int n = nums.size();
        int localMax = 0;
        int localMin = 0;
        for(int i=0;i<n;i++)
        {
            localMax += nums[i];
            if(localMax < 0)
            {
                localMax = 0;
            }
            maxS = max(maxS,localMax);
        }
        for(int i=0;i<n;i++)
        {
            localMin += nums[i];
            if(localMin > 0)
            {
                localMin = 0;
            }
            minS = min(minS,localMin);
        }
        minS = abs(minS);
        return max(minS,maxS);
        
    }
};