class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0]*n]*m
        for i in range(m):
            dp[i][0] = 1
        dp[0] = [1]*n
        for i in range(1,m):
            for j in range(1,n):
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])
        return dp[m-1][n-1]

        