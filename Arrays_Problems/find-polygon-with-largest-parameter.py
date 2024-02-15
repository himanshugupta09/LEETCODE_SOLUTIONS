class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        pre = [nums[0]]
        for i in range(1,len(nums)):
            pre.append(nums[i]+pre[-1])
        mx = float('-inf')
        for i in range(2,n):
            if pre[i-1] > nums[i]:
                mx = max(pre[i],mx)
        
        return mx if mx != float('-inf') else -1
