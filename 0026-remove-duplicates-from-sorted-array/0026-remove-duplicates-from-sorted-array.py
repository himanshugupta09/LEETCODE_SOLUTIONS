class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        res = 1
        for i in range(1,len(nums)):
            if nums[i] != nums[i-1]:
                nums[res] = nums[i]
                res += 1
        return res
        