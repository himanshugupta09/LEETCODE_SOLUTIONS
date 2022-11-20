class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        dp = [0 for i in range(k + 1)]
        dp[0] = sum(cardPoints[:k])

        for i in range(1, k + 1):
            dp[i] = dp[i - 1] - cardPoints[k - i] + cardPoints[-i]

        return max(dp)    