class Solution:
    def minMergedInteger(self, nums: list[int]) -> int:
        nums = [int(str(nums[i])+str(nums[i+1])) for i in range(0,len(nums)-1,2)]
        # print(nums)
        return min(nums)
        