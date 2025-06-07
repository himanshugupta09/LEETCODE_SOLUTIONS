class Solution:
    def clearStars(self, s: str) -> str:
        rem = set()
        min_heap = []
        for i,c in enumerate(s):
            if c == '*':
                rem.add(i)
                rem.add(-heappop(min_heap)[1])
            else:
                heappush(min_heap,(c,-i))
        return ''.join(c for i,c in enumerate(s) if i not in rem)
                
        