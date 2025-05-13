class Solution {
public:
    static constexpr int mod = 1000000007;
    int lengthAfterTransformations(string s, int t) {
       vector<int>cnt(26,0);
       for(char c: s)
       {
            ++cnt[c-'a'];
       }
       for(int turns=0;turns<t;turns++)
       {
            vector<int>nt(26,0);
            nt[0] = cnt[25];
            nt[1] = (cnt[25]+cnt[0])%mod;
            for(int i=2;i<26;i++)
            {
                nt[i] = cnt[i-1];
            }
            cnt = move(nt);

       }
       int res = 0;
       for(int i=0;i<26;i++)
       {
            res = (res+cnt[i])%mod;
       }
       return res;
    }
};