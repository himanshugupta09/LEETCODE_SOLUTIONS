class Solution {
public:

    bool ishelp(vector<int>nums,int st,int ele)
    {
        return nums[st] != ele;
    }
    bool existIn(vector<int> &nums,int st,int ele)
    {
        return nums[st] <= ele;
    }

    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int low = 0,high = n-1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] == target)
            {
                return true;
            }
            if(!ishelp(nums,low,nums[mid]))
            {
                low++;
                continue;
            }

            bool pvt = existIn(nums,low,nums[mid]);

            bool tar = existIn(nums,low,target);

            if(pvt^tar)
            {
                if(pvt)
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
            else
            {
                if(nums[mid] < target)
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }

        }
    return false;
        

    }
};
