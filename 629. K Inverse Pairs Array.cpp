class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<int> dp(k+1);
        int mod = 1000000007;
        for(int i=1;i<=n;i++)
        {
            vector<int> temp(k+1);
            temp[0] = 1;
            for(int j=1;j<=k;j++)
            {
                int val = (dp[j] + mod-((j-i)>=0?dp[j-i]:0))%mod;
                temp[j] = (temp[j-1]+val)%mod;
            }
            dp = temp;
        }
        
        return ((dp[k]+mod-(k>0?dp[k-1]:0))%mod);
    }
};
