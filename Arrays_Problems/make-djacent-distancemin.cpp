class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0;i<nums.size()-1;i++)
        {
            int dif = abs(nums[i]-nums[i+1]);
                maxi = max(maxi,dif);
            
        }
        maxi = max(maxi,abs(nums[0]-nums[n-1]));
        return maxi;
    }
};
