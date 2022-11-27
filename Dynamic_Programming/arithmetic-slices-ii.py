class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [defaultdict(int) for _ in range(n)]

        ans = 0
        for i in range(n):
            for j in range(i):
                dif = nums[i] - nums[j]
                dp[i][dif] += dp[j][dif] + 1
                ans += dp[j][dif]
        return ans        
