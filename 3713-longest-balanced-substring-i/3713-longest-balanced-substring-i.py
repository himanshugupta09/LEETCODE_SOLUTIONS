from collections import defaultdict
class Solution:
    def longestBalanced(self, s: str) -> int:
        max_len = 0
        for i in range(0,len(s)):
            hashed = defaultdict(int)
            for j in range(i,len(s)):
                hashed[ord(s[j])-97] += 1
                #print(len(set(hashed)))
                if len(set(hashed.values())) == 1:
                    max_len = max(max_len,(j-i+1))
        return max_len