class Solution {
public:
    int binarySearch(vector<int>&nums,int l,int r,int x)
    {
        while(r >= l && r < nums.size())
        {
            int mid = (l+r)/2;
            if(nums[mid] >= x)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return l;
    }
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res = 0;
        
        for(int i=0;i<n-2;i++)
        {
            int k= i+2;
            for(int j=i+1;j<n-1 && nums[i] != 0;j++)
            {
                k = binarySearch(nums,k,n-1,nums[i]+nums[j]);
                res += k-j-1;
            }
        }
        return res;
    }
};