class Solution {
public:
    int binarySearch(int ele,vector<int>nums)
    {
        int lo = 0;
        int res = nums.size();
        int hi = nums.size()-1;
        
        while(lo <= hi)
        {
            int m = lo + (hi-lo)/2;
            if(nums[m] >= ele)
            {
                res = m;
                hi = m-1;
            }
            else
            {
                lo = m+1;
            }
        }
        return res;
    }
    int specialArray(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=1;i<=n;i++)
        {
            int counts = binarySearch(i,nums);
            
            if(n-counts == i)
            {
                return i;
            }
            
        }
        return -1;
    }
};
