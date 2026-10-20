class Solution:
    def reversePairs(self, nums: list[int]) -> int:
        import bisect
        arr = []
        res = 0
        for i in range(len(nums)-1,-1,-1):
            idx = bisect.bisect_left(arr, nums[i] / 2)
            res += (idx-0)
            bisect.insort(arr,nums[i])
        return res
        