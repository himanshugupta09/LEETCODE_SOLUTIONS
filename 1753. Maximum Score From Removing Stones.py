import heapq
class Solution(object):
    def maximumScore(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """
        
        h = [-a,-b,-c]
        
        score = 0
        
        heapq.heapify(h)
        
        while len(h) > 1:
            d = heapq.heappop(h) + 1
            e = heapq.heappop(h) + 1
            
            if d != 0:
                heapq.heappush(h,d)
            if e != 0:
                heapq.heappush(h,e)
                
            score += 1
            
        return score
