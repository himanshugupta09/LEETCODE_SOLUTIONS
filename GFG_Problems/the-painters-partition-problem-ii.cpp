class Solution {
  public:
    bool canPaint(vector<int>&arr,int mid,int k)
    {
        int count = 1;
        int curr = 0;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            if(curr+arr[i] <= mid)
            {
                curr += arr[i];
            }
            else
            {
                count++;
                curr = arr[i];
            }
        }
        return count <= k;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int res = 0;
        int left = *max_element(arr.begin(),arr.end());
        int right = accumulate(arr.begin(),arr.end(),0);
        
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(canPaint(arr,mid,k))
            {
                res = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return res;
        
    }
};
