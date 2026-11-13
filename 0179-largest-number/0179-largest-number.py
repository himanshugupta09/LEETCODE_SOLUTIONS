from functools import cmp_to_key
class Solution:
    def largestNumber(self, nums: list[int]) -> str:
        nums = list(map(str,nums))
        def compare(a,b):
            if a+b > b+a:
                return -1
            elif a+b < b+a:
                return 1
            else:
                return 0
        nums.sort(key=cmp_to_key(compare))
        res = ''.join(nums)
        return '0' if res[0] == '0' else res
        