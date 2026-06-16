class Solution:
    
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        i = 0
        j = 0
        g.sort()
        s.sort()
        res = 0
        while i < len(s) and j < len(g):
            if s[i] >= g[j]:
                res += 1
                j += 1
            i += 1
        return res

        