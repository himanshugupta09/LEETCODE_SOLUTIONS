class Solution:
    import math
    def findGCD(self, nums: List[int]) -> int:
        a = max(nums)
        b = min(nums)
        return math.gcd(a,b)
        