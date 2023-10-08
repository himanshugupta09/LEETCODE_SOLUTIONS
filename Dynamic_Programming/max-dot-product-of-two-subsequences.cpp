class Solution {
public:
    vector<vector<int>>memo;

    int solve(int i,int j,vector<int>& nums1,vector<int>& nums2)
    {
        if(i == nums1.size() || j == nums2.size())
        {
            return 0;
        }
        if(memo[i][j] != 0)
        {
            return memo[i][j];
        }
        int use = nums1[i]*nums2[j] +  solve(i+1,j+1,nums1,nums2);
        memo[i][j] = max(use, max(solve(i + 1, j, nums1, nums2), solve(i, j + 1, nums1, nums2)));
        return memo[i][j];
    
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int max1 = INT_MIN;
        int max2 = INT_MIN;

        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for(auto i:nums1)
        {
            max1 = max(i,max1);
            min1 = min(min1,i);
        }
        for(auto i:nums2)
        {
            max2 = max(max2,i);
            min2 = min(min2,i);
        }
        if(max1 < 0 && min2 > 0)
        {
            return max1*min2;
        }
        if(min1 > 0 && max2 < 0)
        {
            return min1*max2;
        }
        memo = vector(nums1.size(),vector(nums2.size(),0));
        return solve(0,0,nums1,nums2);
    }
};
