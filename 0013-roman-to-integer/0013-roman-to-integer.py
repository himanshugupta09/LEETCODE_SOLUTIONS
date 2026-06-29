class Solution:
    def romanToInt(self, s: str) -> int:
        mapp = {"I": 1,"V": 5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        number =  0
        i = len(s)-1
        while i >= 0:
            if i != 0 and mapp[s[i]] > mapp[s[i-1]]:
                number += (mapp[s[i]]-mapp[s[i-1]])
                i -= 2
                continue
            number += mapp[s[i]]
            i -= 1
        return number