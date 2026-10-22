class Solution:
    def splitArray(self, nums: list[int], k: int) -> int:
        n = len(nums)
        if k-1 == n-1:
            return max(nums)
        lo = max(nums)
        hi = sum(nums)

        def is_feasible(max_sum):
            sum = 0
            split = 0
            for num in nums:
                if num+sum <= max_sum:
                    sum += num
                else:
                    sum = num
                    split += 1
            return split+1

        while lo <= hi:
            mid = lo + (hi-lo)//2
            if is_feasible(mid) <= k:
                hi = mid-1
            else:
                lo = mid+1
        return lo

        
        