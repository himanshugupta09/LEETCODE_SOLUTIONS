class Solution:
    def checkString(self, s: str) -> bool:
        last_a = -1
        first_b = len(s)
        for i in range(len(s)):
            if s[i] == 'a':
                last_a = max(i,last_a)
            else:
                first_b = min(first_b,i)
        return last_a < first_b