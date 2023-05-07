class Solution:
    def distinctDifferenceArray(self, nums: List[int]) -> List[int]:
        res = []
        if len(nums) == 1:
            return [1]
        else:
            for i in range(len(nums)):
                if i == 0:
                    res.append(len(set(nums[:i+1])) - len(set(nums[1:])))
                else:
                    res.append(len(set(nums[:i+1])) - len(set(nums[i+1:])))
            return res        
