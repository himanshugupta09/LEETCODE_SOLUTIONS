class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int res = 0;
        unordered_map<int,int>mpp;
        int l = 0;
        for(int r=0;r<arr.size();r++)
        {
            mpp[arr[r]]++;
            
            
            while(l <= r && mpp.size() > k)
            {
                mpp[arr[l]]--;
                if(mpp[arr[l]]  == 0)
                {
                    mpp.erase(arr[l]);
                }
                l++;
            }
            res += (r-l+1);
        }
        return res;
    }
};
