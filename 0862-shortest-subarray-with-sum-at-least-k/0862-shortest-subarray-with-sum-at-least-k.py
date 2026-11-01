from collections import deque
class Solution:
    def shortestSubarray(self, nums: list[int], k: int) -> int:
        q = deque()
        prefix_sum = [0]
        for i in range(0,len(nums)):
            prefix_sum.append(prefix_sum[-1]+nums[i])
        min_len = float('inf')
        for right in range(len(prefix_sum)):
            while q and prefix_sum[right] - prefix_sum[q[0]] >= k:
                min_len = min(min_len,right-q.popleft())
            while q and prefix_sum[right] <= prefix_sum[q[-1]]:
                q.pop()
            q.append(right)
        return min_len if min_len != float('inf') else -1

