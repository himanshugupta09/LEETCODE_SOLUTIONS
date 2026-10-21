class Solution:
    def minOperations(self, s: str) -> int:
        n = len(s)
        ls = ''.join(sorted(s))

        if s == ls:
            return 0

        if n <= 2:
            return -1

        mn = ls[0]
        mx = ls[-1]

        # One operation is enough if either endpoint is correct
        if s[0] == mn or s[-1] == mx:
            return 1

        # Both extreme characters are at the wrong endpoints
        if s[0] == mx and s[-1] == mn:
            if s.count(mn) > 1 or s.count(mx) > 1:
                return 2
            return 3

        return 2