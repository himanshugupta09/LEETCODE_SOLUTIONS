class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        res = []
        for i in range(1,len(nums)):
            if nums[i] == nums[i-1]:
                nums[i-1] *=2
                nums[i] = 0
        for i in nums:
            if i != 0:
                res.append(i)
        while len(res) < len(nums):
            res.append(0)
        return res