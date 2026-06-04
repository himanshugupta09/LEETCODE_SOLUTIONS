class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(1,len(nums)):
            if nums[i-1] == nums[i]:
                return nums[i]
        return -1
        