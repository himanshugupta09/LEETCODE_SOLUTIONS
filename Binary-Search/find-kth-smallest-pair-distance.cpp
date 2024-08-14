class Solution {
public:
    int countPairs(vector<int>&nums,int mid)
    {
        int cnt = 0;
        int left = 0;
        
        for(int ri = 0;ri<nums.size();ri++)
        {
            while(nums[ri]-nums[left] > mid)
            {
                left++;
            }
            cnt += (ri-left);
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        int lo = 0;
        int n = nums.size();
        int hi = nums[n-1]-nums[0];
        
        while(lo < hi)
        {
            int mid = (lo+hi)/2;
            int cnt = countPairs(nums,mid);
            if(cnt < k)
            {
                lo = mid+1;
            }
            else
            {
                hi = mid;
            }
            
        }
        return lo;
    }
};
