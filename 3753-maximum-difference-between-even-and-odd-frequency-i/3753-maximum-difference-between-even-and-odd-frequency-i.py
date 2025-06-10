class Solution:
    def maxDifference(self, s: str) -> int:
        mp =  {}
        for i in s:
            if i not in mp:
                mp[i] = 1
            else:
                mp[i] += 1
        max_odd = -float('inf')
        min_eve = float('inf')
        for i in mp.values():
            if i%2:
                max_odd = max(max_odd,i)
            else:
                min_eve = min(min_eve,i)
        return max_odd-min_eve