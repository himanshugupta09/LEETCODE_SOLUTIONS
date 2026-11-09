from sortedcontainers import SortedList

class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:

        busy = []
        free = SortedList(range(k))

        service_count = [0] * k

        for i in range(len(arrival)):

            # Release servers that have completed their requests
            while busy and busy[0][0] <= arrival[i]:
                time, server = heappop(busy)
                free.add(server)

            # If no server is free, drop the request
            if not free:
                continue

            # Find the preferred server
            preferred = i % k

            # Find the next available server
            idx = free.bisect_left(preferred)

            if idx == len(free):
                idx = 0

            server = free.pop(idx)

            # Assign request to server
            finish_time = arrival[i] + load[i]

            heappush(busy, (finish_time, server))

            service_count[server] += 1

        # Return all servers with maximum requests
        maximum = max(service_count)

        return [i for i in range(k) if service_count[i] == maximum]
