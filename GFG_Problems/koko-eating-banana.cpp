class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int high = *max_element(arr.begin(),arr.end());
        //int sum = accumulate(arr.beign(),arr.end(),0);
        int low = 1;
        int res = INT_MAX;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int cur = 0;
            for(int i:arr)
            {
                cur += ceil((double)i/mid);
            }
            if(cur <= k)
            {
                res  = min(res,mid);
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
            
        }
        return res ==INT_MAX ? -1 : res;
        
        
    }
};
