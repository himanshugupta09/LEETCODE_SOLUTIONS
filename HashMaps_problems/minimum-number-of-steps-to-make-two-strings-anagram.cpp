class Solution {
public:
    int minSteps(string s, string t) {
     
        int cnt[26] = {0};
        
        for(int i=0;i<s.size();i++)
        {
            cnt[s[i] -'a']--;
            cnt[t[i]-'a']++;
        }
        int res = 0;
        
        for(int i=0;i<26;i++)
        {
            res += max(0,cnt[i]);
        }
        return res;
    }
};
