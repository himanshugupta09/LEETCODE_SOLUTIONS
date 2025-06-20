class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n%k != 0)
        {
            return false;
        }
        sort(arr.begin(),arr.end());
        int res = 1;
        for(int i=1;i<n;i++)
        {
            if(arr[i] == arr[i-1])
            {
                continue;
            }
            else if(arr[i]-arr[i-1] == 1)
            {
                res++;
            }
            else
            {
                if(res%k != 0)
                {
                    return false;
                }
                res = 1;
            }
        }
        return res%k == 0;
        
    }
};
