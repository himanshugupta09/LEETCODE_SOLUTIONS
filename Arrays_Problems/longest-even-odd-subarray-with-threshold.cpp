class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        
        int res = 0;
        
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i]%2 == 0 && nums[i] <= threshold)
            {
                int j = i+1;
                while(j < n && nums[j] <= threshold && nums[j]%2 != nums[j-1]%2)
                {

                    j++;
                }
                res = max(res,j-i);
            }
        }
        return res;
    }
};
