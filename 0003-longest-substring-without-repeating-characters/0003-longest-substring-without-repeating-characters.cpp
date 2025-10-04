class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>cache;
        int n = s.size();
        int j = 0;
        
        int maxLen = 0;
        for(int i=0;i<n;i++)
        {
            while(cache.find(s[i]) != cache.end())
            {
               cache.erase(s[j]);
               j++;
            }
            cache.insert(s[i]);
            maxLen = max(maxLen,(i-j+1));
        }
        return maxLen;
    }
    
};