class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 0;
        
        int left = 0;
        int n = nums.size();
        multiset<int>mt;
        
        for(int i=0;i<n;i++)
        {
            mt.insert(nums[i]);
            
            while(*mt.rbegin()-*mt.begin() > limit)
            {
                mt.erase(mt.find(nums[left]));
                left++;
            }
            res = max(res,i-left+1);
        }
        return res;
    }
};
