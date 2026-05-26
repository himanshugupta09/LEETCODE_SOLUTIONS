class Solution:
    def numberOfSpecialChars(self, s: str) -> int:
        seen = set(s)
        return sum(c in s and c.upper() in s for c in string.ascii_lowercase)
        