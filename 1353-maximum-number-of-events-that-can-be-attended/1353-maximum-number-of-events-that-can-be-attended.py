import heapq
class Solution:
    def maxEvents(self, events: list[list[int]]) -> int:
        events.sort()
        heap = []
        day = 0
        total_attends = 0
        n = len(events)
        i = 0

        while i < n or heap:
            if not heap:
                day = max(day,events[i][0])
            while i < n and events[i][0] <= day:
                heapq.heappush(heap,events[i][1])
                i += 1
            while heap and heap[0] < day:
                heapq.heappop(heap)
            if heap:
                total_attends += 1
                heapq.heappop(heap)
                day += 1

        return total_attends
        