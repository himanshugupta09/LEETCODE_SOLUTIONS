from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        q = deque()  # stores indices

        for i in range(k):
            while q and nums[q[-1]] <= nums[i]:
                q.pop()
            q.append(i)

        res.append(nums[q[0]])

        for i in range(k, len(nums)):
            while q and q[0] <= i - k:
                q.popleft()

            while q and nums[q[-1]] <= nums[i]:
                q.pop()

            q.append(i)
            res.append(nums[q[0]])

        return res