class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        nums.sort()
        mid = 0 + (len(nums)-0)//2
        res = 0
        for i in range(len(nums)):
            res += abs(nums[i]-nums[mid])
        return res
        