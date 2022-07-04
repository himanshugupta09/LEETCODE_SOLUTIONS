class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        i,j = 0,0
        ans = 999999
        n = len(nums)
        sm = nums[i]
        while i<n and j<n:
            
            if sm >= target:
                temp_length = j-i+1
                
                ans = min(ans,temp_length)
                sm -=nums[i]
                i += 1
                
            else:
                if j+1<n:
                    j += 1
                    sm += nums[j]
                else:
                    j += 1
                
        if ans == 999999:
            return 0
        else:
            return ans
