class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        left_sum = 0
        res = []
        n = len(nums)
        nums.append(0)
        left_sum_arr = []
        right_sum_arr = []
        for i in range(n):
            left_sum_arr.append(left_sum)
            left_sum += nums[i]
        for i in range(n):
            right_sum_arr.append(sum(nums[i+1:]))
        for i in range(n):
            res.append(abs(left_sum_arr[i]-right_sum_arr[i]))
        return res