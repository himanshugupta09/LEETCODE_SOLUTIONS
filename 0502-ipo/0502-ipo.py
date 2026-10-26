import heapq
class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: list[int], capital: list[int]) -> int:
        heap = []
        temp_heap = []
        for i in range(len(profits)):
            heapq.heappush(heap,[capital[i],profits[i]])
        
        count = 0
        while count < k:
            while heap and heap[0][0] <= w:
                heapq.heappush(temp_heap,-heap[0][1])
                heapq.heappop(heap)
            if not temp_heap:
                break
            w += abs(temp_heap[0])
            heapq.heappop(temp_heap)
            count += 1
        return w