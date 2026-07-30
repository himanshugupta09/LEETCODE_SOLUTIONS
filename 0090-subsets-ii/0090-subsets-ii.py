class Solution:
    def solve(self,idx,nums,res,arr):
        if idx == len(nums):
            res.append(arr[:])
            return
        arr.append(nums[idx])
        self.solve(idx+1,nums,res,arr)
        arr.pop()
        while idx + 1 < len(nums) and nums[idx] == nums[idx + 1]:
            idx += 1
        self.solve(idx+1,nums,res,arr)

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        self.solve(0,nums,res,[])
        return res