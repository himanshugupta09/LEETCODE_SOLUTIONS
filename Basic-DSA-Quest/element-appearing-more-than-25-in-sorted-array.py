class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        mp = {}
        tf = len(arr)//4
        for i in arr:
            if i in mp:
                mp[i] += 1
            else:
                mp[i] = 1
        res = 0
        for key,val in mp.items():
            if val > tf:
                res = key
                break
        return res
        
