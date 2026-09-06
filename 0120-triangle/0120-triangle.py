class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        dp = [0]*(n+1)
        for i in triangle[::-1]:
            for j,m in enumerate(i):
                dp[j] = m + min(dp[j],dp[j+1])
        return dp[0]

        #this is just for making sure the streak
        for i in range(0):
            pass
