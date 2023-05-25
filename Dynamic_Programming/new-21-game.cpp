class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double>dp(n+1);
        dp[0] = 1;

        double t = k > 0 ? 1: 0;

        for(int i=1;i<=n;i++)
        {
            dp[i] = t/maxPts;
            if(i < k)
            {
                t += dp[i];


            }
            if(i - maxPts >= 0 && i-maxPts < k)
            {
                t -= dp[i-maxPts];

            }
        }
        return accumulate(dp.begin()+k,dp.end(),0.0);
    }
};
