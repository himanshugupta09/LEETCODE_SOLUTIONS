class Solution:
    def frequencySort(self, s: str) -> str:
        mp = {}
        for char in s:
            if char in mp:
                mp[char] += 1
            else:
                mp[char] = 1
        dt = []
        for key,val in mp.items():
            dt.append([val,key])
        del mp
        dt.sort()
        res = ''
        
        for i in range(len(dt)-1,-1,-1):
            res += (dt[i][0]*dt[i][1])
        del dt
        return res
        
