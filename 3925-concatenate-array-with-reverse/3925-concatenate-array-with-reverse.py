class Solution:
    def concatWithReverse(self, nums: list[int]) -> list[int]:
        
        n = len(nums)
        i = n-1
        while i >= 0:
            nums.append(nums[i])
            i -= 1
        return nums
        