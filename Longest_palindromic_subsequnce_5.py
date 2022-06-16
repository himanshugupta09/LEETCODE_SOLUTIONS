class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expC(self, str: S, left: int, right: int):
            L = left
            R = right
            while (L >= 0 and R < len(s) and s[L] == s[R]):
                L -= 1
                R += 1
            return R - L - 1

        if s == '' or len(s) < 1:
            return " "
        st, e = 0, 0
        for i in range(0, len(s)):
            l1 = expC(s, st, i, i)
            l2 = expC(s, st, i, i + 1)
            ln = max(l1, l2)
            if (ln > e - st):
                st = i - (ln - 1) // 2
                e = i + (ln // 2)
        return s[st:e + 1]



