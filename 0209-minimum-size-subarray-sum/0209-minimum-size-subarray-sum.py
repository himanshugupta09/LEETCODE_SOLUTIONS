class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        min_len = float('inf')
        i = 0
        cur_sum = 0
        for j in range(len(nums)):
            cur_sum += nums[j]
            while cur_sum >= target:
                if cur_sum >= target:
                    min_len = min(min_len,(j-i+1))
                cur_sum -= nums[i]
                i += 1
            
        return min_len if min_len != float('inf') else 0

        