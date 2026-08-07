from collections import Counter
class Solution:
    def minDeletions(self, s: str) -> int:
        freq = Counter(s)
        seen_freq = set()
        dels = 0
        for val in freq.values():
            while val > 0 and val in seen_freq:
                val -= 1
                dels += 1
            if val  > 0:
                seen_freq.add(val)
        return dels
