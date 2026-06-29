class Solution:
    def reverseWords(self, s: str) -> str:
        ls = s.split()
        n = len(ls)
        for i in range(n//2):
            ls[i],ls[n-i-1] = ls[n-i-1],ls[i]
        return " ".join(ls)