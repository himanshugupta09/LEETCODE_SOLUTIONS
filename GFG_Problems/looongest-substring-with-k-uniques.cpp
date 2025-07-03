class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int longest = INT_MIN;
        unordered_map<char,int>mpp;
        int l= 0;
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]++;
            if(mpp.size()  == k)
            {
                longest = max(longest,(i-l+1));
            }
            while(l < i && mpp.size() > k)
            {
                mpp[s[l]]--;
                if(mpp[s[l]] == 0)
                {
                    mpp.erase(s[l]);
                }
                l++;
            }
        }
        return longest == INT_MIN ? -1 : longest;
    }
};
