class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int>lookUp(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
           
           if(!lookUp.contains(nums[i]-1))
           {
                int currEle = nums[i];
                while(lookUp.contains(currEle+1))
                {
                    lookUp.erase(currEle);
                    currEle++;
                }
                maxLen = max(maxLen,currEle-nums[i]+1);
           }
        }
        return maxLen;

    }
};