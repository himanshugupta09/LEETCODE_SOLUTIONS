from collections import defaultdict
class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        left = 0
        right = 0
        n = len(nums)
        longest = 0
        while right < n:
            mp[nums[right]] += 1

            while left < right and mp[nums[right]] > k:
                mp[nums[left]] -= 1
                left += 1
            length = right-left+1
            longest = max(longest,length)
            right += 1
        return longest

