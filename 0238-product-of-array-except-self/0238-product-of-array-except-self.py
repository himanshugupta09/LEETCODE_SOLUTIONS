class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        pref = 1
        suff = 1
        res = [1 for i in range(n)]
        for i in range(n):
            res[i] *= pref
            pref *= nums[i]
        for i in range(n-1,-1,-1):
            res[i] *= suff
            suff *= nums[i]
        return res
            