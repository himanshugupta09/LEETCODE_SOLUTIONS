// User function template for C++

class Solution {
  public:

    bool checkWithinK(vector<int>& arr, int k) {
        // your code
        int n = arr.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(arr[i]) != mp.end() && (abs(mp[arr[i]]-i)<=k))
            {
                return true;
            }
            else
            {
                mp[arr[i]]=i;
            }
        }
        return false;
    }
};
