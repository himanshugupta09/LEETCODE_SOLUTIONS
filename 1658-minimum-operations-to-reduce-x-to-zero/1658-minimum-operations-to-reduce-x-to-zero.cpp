class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int remains = totalSum-x;

        if(x > totalSum || remains < 0){
            return -1;
        }
        if(remains == 0)
        {
            return nums.size();
        }
        int longest = -1;
        int left = 0;
        int currSum = 0;
        for(int right = 0;right < nums.size();right++)
        {
            currSum += nums[right];
            if(currSum == remains)
            {
                int len = right-left+1;
                if(len > longest)
                {
                    longest = len;
                }
            }
            else
            {
               while(currSum > remains)
               {
                    currSum -= nums[left];
                    left++;
               }
               if(currSum == remains)
               {
                    int len = right-left+1;
                    if(len > longest)
                    {
                        longest = len;
                    }
               }
            }
        }
        //cout << longest;
        return longest == -1 ? -1 : nums.size()-longest;
    }
};