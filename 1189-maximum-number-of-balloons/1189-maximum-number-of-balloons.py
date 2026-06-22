from collections import defaultdict
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        mp = defaultdict(int)
        valid = set(['a','b','l','o','n'])
        for char in text:
            if char in valid:
                mp[char] += 1
        return min(
    mp['b'],
    mp['a'],
    mp['n'],
    mp['l'] // 2,
    mp['o'] // 2
)
        