class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        max_len = 0
        
        seen = set()
        for j in range(0,len(s)):
            if s[j] not in seen:
                seen.add(s[j])
                max_len = max(max_len,len(seen))
            else:
                while s[j] in seen:
                    seen.remove(s[i])
                    i += 1
                seen.add(s[j])
        return max_len
        