class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        
        res = []
        n = len(nums)
        i = 0
        while i <= n-3:
            if (nums[i+1]-nums[i] <= k) and (nums[i+2]-nums[i] <= k) and (nums[i+2]-nums[i+1] <= k):
                res.append([nums[i],nums[i+1],nums[i+2]])
                i += 3
            else:
                break
        if i == n:
            return res
        return []
            
        
