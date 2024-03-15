class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [1] * n
        
        # Compute prefix products
        prefix_product = 1
        for i in range(n):
            res[i] *= prefix_product
            prefix_product *= nums[i]
        
        # Compute suffix products while updating the result list
        suffix_product = 1
        for i in range(n - 1, -1, -1):
            res[i] *= suffix_product
            suffix_product *= nums[i]
        
        return res
