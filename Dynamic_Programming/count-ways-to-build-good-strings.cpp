class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int  md = 1e9+7;
        vector<int>dp(high+1);
        dp[0] = 1;

        for(int i = 1;i<=high;i++)
        {
            if(i >= zero)
            {
                dp[i] += dp[i-zero];
            }
            if(i >= one)
            {
                dp[i] += dp[i-one];
            }
            dp[i]%=md;
        }
        int res = 0;

        for(int i=low;i<=high;i++)
        {
            res += dp[i];
            res %= md;
        }
        return res;

    }
};
