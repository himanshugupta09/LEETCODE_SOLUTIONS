class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        n = len(words)
        min_dist = n

        for i,word in enumerate(words):
            if word == target:
                min_dist = min(min_dist,abs(i-startIndex),n-abs(i-startIndex))
        return min_dist if min_dist < n else -1
        