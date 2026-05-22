class Solution {
public:
    int binarySearch(vector<int>&nums,int low,int high,int target)
    {
        int l = low;
        int r = high;

        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {

        int low = 0;
        int n = nums.size();
        int high = n-1;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] > nums[n-1])
            {
                low = mid+1;
            }
            else 
            {
                high = mid-1;
            }
        }
        int res = binarySearch(nums,0,low-1,target);

        if(res != -1)
        {
            return res;
        }
        return binarySearch(nums,low,n-1,target);
        
    }
};