import heapq
class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        n = len(courses)
        if n == 1 and courses[0][0] >= courses[0][1]:
            return 1
        diffs = [[i,courses[i]] for i in range(n)]
        diffs.sort(key=lambda x:x[1][1])
        took = 0
        last_day = 0
        i = 0

        max_heap = []
        while i < n:
            idx = diffs[i][0]
            dur = courses[idx][0]
            last_day_t = courses[idx][1]
            if last_day + dur <=  last_day_t:
                last_day += dur
                heapq.heappush(max_heap,[-dur,last_day_t])
                took += 1
            else:
                if max_heap:
                    lasp = -max_heap[0][0]
                    if lasp > dur:
                        heapq.heappop(max_heap)
                        dt = lasp
                        last_day -= dt
                        last_day += dur
                        heapq.heappush(max_heap,[-dur,last_day_t])
                        

            i += 1
        return took


        