from bisect import bisect_left
from collections import defaultdict
from typing import List

class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        mpp = defaultdict(list)
        n = len(nums)
        
        for i, num in enumerate(nums):
            mpp[num].append(i)
        
        res = []
        
        for q in queries:
            indices = mpp[nums[q]]
            
            if len(indices) < 2:
                res.append(-1)
                continue
            
            pos = bisect_left(indices, q)
            ans = float('inf')
            
            # left neighbor
            if pos > 0:
                ans = min(ans, abs(q - indices[pos - 1]))
            
            # right neighbor
            if pos < len(indices) - 1:
                ans = min(ans, abs(q - indices[pos + 1]))
            
            # circular neighbors
            ans = min(ans, n - abs(q - indices[0]))
            ans = min(ans, n - abs(q - indices[-1]))
            
            res.append(ans)
        
        return res