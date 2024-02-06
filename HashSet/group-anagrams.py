class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        mp = {}
        n = len(strs)
        #print(ord('a'))
        for i in range(n):
            mpr = [0]*26
            for char in strs[i]:
                mpr[ord(char)-97] += 1
            mpt = tuple(mpr)    
            if mpt not in mp:
                mp[mpt] = [strs[i]]
            else:
                mp[mpt].append(strs[i])
        res = []
        
        for i in mp.values():
            res.append(i)
        del mp
        return res
        
