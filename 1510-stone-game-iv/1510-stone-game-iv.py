class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp = [False] * (n + 1)

        # dp[0] = False
        # No move possible when n = 0

        for i in range(1, n + 1):
            x = 1

            while x * x <= i:
                if dp[i - x * x] == False:
                    dp[i] = True
                    break

                x += 1

        return dp[n]
