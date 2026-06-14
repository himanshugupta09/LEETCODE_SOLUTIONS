class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max_streak = 0
        local_max = 0
        for num in nums:
            if num:
                local_max += 1
            else:
                max_streak = max(max_streak,local_max)
                local_max = 0
        return max(max_streak,local_max)
        