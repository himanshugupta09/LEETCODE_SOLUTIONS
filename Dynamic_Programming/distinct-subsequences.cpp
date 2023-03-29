class Solution {
public:
    int distinctSubseqII(string s) {
        const int mod = 1e9+7;
        int n = s.size();
        vector<int>dp(n+1);
        dp[0] = 1;
        dp[1] = 2;

        vector<int>last(26,-1);


        for(int i=0;i<n;i++)
        {
            int x = s[i]-'a';
            dp[i+1] = dp[i]*2%mod;
            if(last[x] >= 0)
            {
                dp[i+1] -= dp[last[x]];
            }
            dp[i+1] %= mod;
            last[x]  = i;

        }
        dp[n]--;
        if(dp[n] < 0)
        {
            dp[n] += mod;
        }
        return dp[n];
    }
};
