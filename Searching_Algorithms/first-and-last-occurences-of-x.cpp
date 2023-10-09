class Solution {
public:
    int lowerBound(vector<int>& arr,int n,int k)
    {
        int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            first = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return first;
    }
    int upperBound(vector<int>& arr,int n,int k)
    {
        int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            last = mid;
            //look for larger index on the right
            low = mid + 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int low = 0,high = nums.size()-1;

        int idx = -1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(nums[mid] == target)
            {
                idx = mid;
                break;
            }
            else if(nums[mid] < target)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        if(idx == -1)
        {
            return {-1,-1};
        }
        int up = upperBound(nums,nums.size(),target);
        int lo = lowerBound(nums,nums.size(),target);

        return {lo,up};

    }
};
