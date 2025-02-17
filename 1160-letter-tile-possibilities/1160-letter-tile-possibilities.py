class Solution:
    def _formString(self,charCount):
        tot = 0
        for i in range(26):
            if charCount[i] == 0:
                continue
            tot += 1
            charCount[i] -= 1
            tot += self._formString(charCount)
            charCount[i] += 1
        return tot
    def numTilePossibilities(self, tiles: str) -> int:
        charCount = [0]*26
        for i in tiles:
            charCount[ord(i)-ord('A')] += 1
        return self._formString(charCount)        