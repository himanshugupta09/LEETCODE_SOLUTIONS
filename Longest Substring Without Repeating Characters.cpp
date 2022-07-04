class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256,-1);
        int maxl = 0,start = -1;
        for(int i=0;i<s.size();i++)
        {
            if(dict[s[i]]>start)
            {
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            maxl = max(maxl,i-start);
        }
        return maxl;
        
        
    }
};
# In this approach we had used Hashset Technique in which We created a array and intialised it with -1
# as a Character is read we increament its corresponding values with its index in string 
