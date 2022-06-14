class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n, m = len(word1), len(word2)
        dp = [[0 for i in range(n + 1)] for j in range(m + 1)]

        for i in range(m):
            for j in range(n):
                if word2[i] == word1[j]:
                    dp[i + 1][j + 1] = dp[i][j] + 1
                else:
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j], dp[i][j])

        return n + m - dp[i + 1][j + 1] * 2
