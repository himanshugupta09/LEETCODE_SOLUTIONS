class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        
        mp = {}
        for i in range(len(s)):
            if s[i] in mp:
                mp[s[i]].append(i)
                mp[s[i]].sort()
            else:
                mp[s[i]] = [i]
        mx = -float('inf')
        #print(mp.values())
        for ls in mp.values():
            tp = ls[-1]-ls[0]-1
            mx = max(tp,mx)
        if mx >= 0:
            return mx
        return -1
