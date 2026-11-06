class Solution:
    def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
        logs.sort(key = lambda x:x[1])
        ids = sorted(range(len(queries)), key = lambda i: queries[i])
        res = [0]*len(queries)
        cnt = [0]*(n+1)
        left = right = active = 0
        
        for i in ids:
            q = queries[i]
            while right < len(logs) and logs[right][1] <= q:
                id = logs[right][0]
                if cnt[id] == 0:
                    active += 1
                cnt[id] += 1
                right += 1
            while left < right and logs[left][1] < q - x:
                id = logs[left][0]
                cnt[id] -= 1
                if cnt[id] == 0:
                    active -= 1
                left += 1
            res[i] = n-active
        return res


        