class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix_count = defaultdict(int)
        prefix_count[0] = 1
        current_sum = 0
        res = 0

        for num in nums:
            current_sum += num
            res += prefix_count[current_sum-k]
            prefix_count[current_sum] += 1
        return res
