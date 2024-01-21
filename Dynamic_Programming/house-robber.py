class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        incl = [0]*n
        incl[0] = nums[0]
        exc = [0]*n
        
        incer = 0
        excer = 0
        
        for i in range(1,n):
            incer = exc[i-1]+nums[i]
            excer = max(incl[i-1],exc[i-1])
            
            incl[i] = incer
            exc[i] = excer
        return max(incl[n-1],exc[n-1])
