class Solution:
    def shipWithinDays(self, weights: list[int], days: int) -> int:
        def canShip(max_weight):
            day = 1
            tot = 0
            for w in weights:
                if tot + w > max_weight:
                    day += 1
                    tot = w
                else:
                    tot += w
            return day <= days
                       

        low = max(weights)
        high = sum(weights)
        res = -1
        while low <= high:
            mid = low + (high - low)//2
            if canShip(mid):
                res = mid
                high = mid-1
            else:
                low = mid+1
        return low