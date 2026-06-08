class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        hash_map = {}
        max_len = 0
        left = 0
        n = len(s)
        for right in range(n):
            if s[right] in hash_map and hash_map[s[right]] >= left:
                left = hash_map[s[right]] + 1
            hash_map[s[right]] = right
            max_len = max(max_len,right-left+1)
        return max_len