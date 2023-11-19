class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int res = 0;
        int ups = 0;
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i] != nums[i-1])
            {
                ups++;
            }
            res += ups;
        }
        return res;
    }
};
