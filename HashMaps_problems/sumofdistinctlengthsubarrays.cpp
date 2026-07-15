class Solution {
  public:
    long long  int mod = 1e9+7;
    
    int sumOfLengths(vector<int>& arr) {
        // code here
        if(arr.size() <= 1)
        {
            return arr.size();
        }
        int res = 0;
        unordered_map<int,int>mp;
        int l = 0,r=0;
       while (r < arr.size()) {
        
            mp[arr[r]]++;
        
            while (mp[arr[r]] > 1) {
                mp[arr[l]]--;
                if (mp[arr[l]] == 0)
                    mp.erase(arr[l]);
                l++;
            }
        
            int len = r - l + 1;
            res += 1LL * len * (len + 1) / 2;
        
            r++;
        }

        return res;
        
    }
};