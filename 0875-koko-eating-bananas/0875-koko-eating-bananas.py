class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        hi = res =  sum(piles)
        lo = 1
        def get_sum(piles,div):
            sum = 0
            for p in piles:
                sum += ceil(p/div)
            return sum
        while lo <= hi:
            mid = lo + (hi-lo)//2
            times = get_sum(piles,mid)
            if times > h:
                lo = mid+1
            elif times <= h:
                hi = mid-1
                res = mid
        return res


