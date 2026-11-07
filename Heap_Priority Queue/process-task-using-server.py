class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        # Busy servers, stored as pairs (t, idx)
        busy = list()

        # Idle servers, stored as pairs (w, idx)
        idle = [(w, i) for i, w in enumerate(servers)]
        heapq.heapify(idle)

        ts = 0

        # Move servers with t<=ts from priority queue busy to priority queue idle one by one
        def release():
            while busy and busy[0][0] <= ts:
                _, idx = heapq.heappop(busy)
                heapq.heappush(idle, (servers[idx], idx))

        ans = list()
        for i, task in enumerate(tasks):
            ts = max(ts, i)
            release()
            if not idle:
                ts = busy[0][0]
                release()

            _, idx = heapq.heappop(idle)
            ans.append(idx)
            heapq.heappush(busy, (ts + task, idx))

        return ans
