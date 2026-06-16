class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        INF = amount + 1

        dp = [INF] * (amount + 1)
        dp[0] = 0

        for i in range(1, amount + 1):
            for coin in coins:
                if i >= coin:
                    dp[i] = min(dp[i], dp[i - coin] + 1)

        return -1 if dp[amount] == INF else dp[amount]