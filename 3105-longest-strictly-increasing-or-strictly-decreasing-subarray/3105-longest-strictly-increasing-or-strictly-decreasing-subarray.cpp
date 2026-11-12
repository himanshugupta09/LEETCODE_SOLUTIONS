class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxL = 1;
        int incL =  1,decL = 1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1] > nums[i])
            {
                incL++;
                decL = 1;
            }
            else if(nums[i+1] < nums[i])
            {
                incL = 1;
                decL++;
            }
            else
            {
                incL = 1;
                decL = 1;

            }
            maxL = max(maxL,max(incL,decL));
        }
        return maxL;
    }
};