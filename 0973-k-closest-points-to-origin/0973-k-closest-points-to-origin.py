import heapq
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        distances = []
        for i in range(len(points)):
            x,y = points[i]
            dist = x**2 + y**2
            distances.append([dist,i])
        res = []
        heapq.heapify(distances)
        while k > 0:
            top = heapq.heappop(distances)
            idx = top[1]
            res.append(points[idx])
            k -= 1
        return res