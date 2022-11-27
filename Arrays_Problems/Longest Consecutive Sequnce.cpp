class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        
        unordered_set<int> intelli(nums.begin(),nums.end());
        
        
        
        int longest = 0;
        
        for(int i = 0;i<nums.size();i++)
        {
            if(intelli.find(nums[i]-1) != intelli.end())
            {
                continue;
            }
            else
            {
                int count = 0;
                int cur_ele = nums[i];
                
                 while(intelli.find(cur_ele) != intelli.end())
                {
                    count++;
                    cur_ele++;
                }
                
                longest = max(longest,count);
            }
        }
        return longest;
    }
};
