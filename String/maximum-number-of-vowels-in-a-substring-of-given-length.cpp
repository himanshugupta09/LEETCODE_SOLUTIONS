class Solution {
public:
    
    int maxVowels(string s, int k) {
        int n = s.size();
        set<char>vow{'a','e','i','o','u'};
        int cnt = 0;

        for(int i=0;i<k;i++)
        {
            cnt += vow.count(s[i]);   
        }

        int ans = cnt;
        

        for(int i=k;i<n;i++)
        {
            cnt += vow.count(s[i]) - vow.count(s[i-k]);
            ans = max(ans,cnt);
        }
        return ans;
    }
};
