import heapq
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        pq = []
        for num in nums:
            heapq.heappush(pq,num)
        res = 0
        while pq[0] < k and len(pq) >= 2:
            a = heapq.heappop(pq)
            b = heapq.heappop(pq)
            new = min(a,b)*2+max(a,b)
            heapq.heappush(pq,new)
            res += 1
        return res