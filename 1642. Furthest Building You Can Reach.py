class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        min_heap = []
        n = len(heights)
        for i in range(n - 1):
            dif = heights[i + 1] - heights[i]
            if dif <= 0:
                continue
            if dif > 0:
                heapq.heappush(min_heap, dif)
            if len(min_heap) > ladders:
                extras = heapq.heappop(min_heap)
                bricks -= extras

            if bricks < 0:
                return i
        return n - 1
