import heapq

class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        n = len(nums)
        D = [-float('inf')] * (n)
        # stores (D[index], index), max heap
        heap = [(-nums[0], 0)]
        
        D[0] = nums[0]
        
        for i in range(1, n):
            # get max D value from before k steps
            (maxValue, index) = heap[0]
            
            # if maxValue is from many steps before(index we can't jump from), abandon it
			# O(logN)
            while index < i - k:
                heapq.heappop(heap)
                (maxValue, index) = heap[0]
            
            D[i] = -maxValue + nums[i]
			# O(logN)
            heapq.heappush(heap, (-D[i], i))

        return D[n-1]
