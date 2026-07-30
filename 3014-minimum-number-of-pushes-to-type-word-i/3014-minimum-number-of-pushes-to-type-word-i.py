class Solution:
    def minimumPushes(self, word: str) -> int:
        res = 0
        for i in range(len(word)):
            res += (i//8)+1
        return res