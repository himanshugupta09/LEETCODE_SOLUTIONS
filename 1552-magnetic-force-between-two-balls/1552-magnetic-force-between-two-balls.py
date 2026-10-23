class Solution:
    def maxDistance(self, positions: list[int], m: int) -> int:
        positions.sort()

        def solve(dist):
            k = 1
            last = positions[0]

            for i in range(1, len(positions)):
                if positions[i] - last >= dist:
                    k += 1
                    last = positions[i]

                    if k >= m:
                        return True

            return False

        low = 1
        high = positions[-1] - positions[0]
        res = 0

        while low <= high:
            mid = low + (high - low) // 2

            if solve(mid):
                res = mid
                low = mid + 1
            else:
                high = mid - 1

        return res