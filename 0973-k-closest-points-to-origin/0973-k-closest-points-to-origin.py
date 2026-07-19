import heapq

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        if not points or k <= 0:
            return []

        max_heap = []

        for x, y in points:
            dist = x**2 + y**2

            if len(max_heap) < k:
                heapq.heappush(max_heap, (-dist, x, y))

            else:
                if -dist > max_heap[0][0]:
                    heapq.heapreplace(max_heap, (-dist, x, y))

        return [[x, y] for _, x, y in max_heap]