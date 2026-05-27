class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        up = {}
        lo = {}
        
        for i in range(len(word)):
            if word[i].islower() and word[i] in lo:
                lo[word[i]] = max(lo[word[i]],i)
            elif word[i].islower() and word[i] not in lo:
                lo[word[i]] = i
            elif word[i].isupper() and word[i] in up:
                up[word[i]] = min(up[word[i]],i)
            elif word[i].isupper() and word[i] not in up:
                up[word[i]] = i
        res = 0
        # print(lo)
        # print(up)
        for up_c,up_i in up.items():
            l = up_c.lower()
            if l in lo and up_i > lo[l]:
                res += 1
        return res