class Solution {
  public:
    bool canAllocate(vector<int>&arr,int curr,int k)
    {
        int count = 1;
        int pageSum = 0;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i] > curr)
            {
                return false;
            }
            if(pageSum+arr[i] <= curr){
                pageSum += arr[i];
            }
            else
            {
                count++;
                pageSum = arr[i];
            }
            
        }
        return count <= k;
        
        
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int res = -1;
        int left = *max_element(arr.begin(),arr.end());
        int right = accumulate(arr.begin(),arr.end(),0);
        if(k > arr.size()) return -1;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(canAllocate(arr,mid,k))
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
