class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_len = 0
        
        hashtable = set()
        left = 0
        for right in range(0,len(s)):
            while left < right and s[right] in hashtable:
                hashtable.remove(s[left])
                left += 1
            hashtable.add(s[right])
            max_len = max(max_len,(right-left+1))
        return max_len
        