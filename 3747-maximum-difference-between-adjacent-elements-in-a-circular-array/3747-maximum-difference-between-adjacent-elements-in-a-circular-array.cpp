class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        
        int n = nums.size();
        int maxy = abs(nums[n-1]-nums[0]);
        for(int i=1;i<n;i++)
        {
            int d = abs(nums[i]-nums[i-1]);
            maxy = max(maxy,d);
        }
        return maxy;
        
    }
};