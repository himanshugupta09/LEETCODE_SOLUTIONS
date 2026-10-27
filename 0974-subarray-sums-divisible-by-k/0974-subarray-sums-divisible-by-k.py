class Solution:
    def subarraysDivByK(self, nums: list[int], k: int) -> int:
        prefix = 0
        freq = {0:1}
        count = 0
        for num in nums:
            prefix += num
            rem = prefix % k
            count += freq.get(rem,0)
            freq[prefix%k] = freq.get(prefix%k,0)+1
        return count
        