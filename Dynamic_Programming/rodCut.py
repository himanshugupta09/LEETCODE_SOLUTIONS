class Solution:
    def cutRod(self, prices):
        #code here
        n = len(prices)
        dp = [i for i in prices]
        dp = [0] + dp
        for i in range(1,n+1):
            cei = i//2
            for j in range(1,cei+1):
                dp[i] = max(dp[i],(dp[j]+dp[i-j]))
        return dp[n]