class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        res = []
        i = 0
        while i+k < len(s):
            t = s[i:i+k]
            res.append(t)
            i += k
        if i != len(s):
            t = abs(k-len(s[i:]))*fill
            p = s[i:]+t
            res.append(p)
        return res
        