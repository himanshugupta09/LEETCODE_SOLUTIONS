class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int,int>mpp;
        int l = 0;
        int res = INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]]++;
            if(mpp.size() <= 2)
            {
                res = max(res,(i-l+1));
            }
            while(mpp.size() > 2 && l < i)
            {
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0)
                {
                    mpp.erase(arr[l]);
                }
                l++;
            }
        }
        return res;
    }
};
