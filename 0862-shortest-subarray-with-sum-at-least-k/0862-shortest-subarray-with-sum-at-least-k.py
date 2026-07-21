from collections import deque
class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        dq = deque()
        prefix = [0]
        for i in range(0,n):
            prefix.append(prefix[-1] + nums[i])
        min_len = float('inf')

        for i in range(n+1):
            while dq and prefix[i] - prefix[dq[0]] >= k:
                min_len = min(min_len,(i-dq[0]))
                dq.popleft()
            while dq and prefix[i] <= prefix[dq[-1]]:
                dq.pop()
            dq.append(i)
        return min_len if min_len != float('inf') else -1
        
