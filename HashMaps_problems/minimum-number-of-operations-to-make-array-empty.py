class Solution:
    def minOperations(self, nums: List[int]) -> int:
        mapper = Counter(nums)
        res = 0
        for val in mapper.values():
            if val == 1:
                return -1
            res += ceil(val/3)
        return res
