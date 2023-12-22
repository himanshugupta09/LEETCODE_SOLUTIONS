class Solution:
    def maxScore(self, s: str) -> int:
        left = ''
        right = ''
        mx = 0
        for i in range(0,len(s)-1):
            left = s[:i+1]
            right = s[i+1:]
            t = left.count('0') + right.count('1')
            mx  = max(mx,t)
        return mx
            
