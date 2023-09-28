class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        res = []
        for i in range(len(nums)):
            if nums[i]%2 == 0:
                res.append(nums[i])
                #del nums[i]
        for i in range(len(nums)):
            if nums[i]%2:
                res.append(nums[i])
        return res
        
        
