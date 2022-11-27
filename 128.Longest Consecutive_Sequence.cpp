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


# Insert all the elements of the array into set.
# Check if the previous number (nums[i] - 1) is present in the set, if it is then that number (nums[i]) is not the starting of the sequence.
# If previous number is not present, that means that number is the starting of the sequence.
# Make a count variable to count the length of the sequence and current variable to store the current number.
# Now in a while loop, traverse and keep searching for consecutive elements until the condition is false.
# Now store the maximum of longest_sequence and current length of the sequence.
