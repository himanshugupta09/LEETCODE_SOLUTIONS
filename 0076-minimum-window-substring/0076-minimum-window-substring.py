from collections import Counter
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        min_len = float('inf')
        res = ''
        i = 0
        hash_map1 = Counter()
        for k in t:
            hash_map1[k] += 1
        #print(hash_map1)
        hash_map2 = Counter()
        n = len(s)
        if len(t) > len(s):
            return ""
        req = len(hash_map1)
        form = 0
        for j in range(n):
            hash_map2[s[j]] += 1
            if hash_map2[s[j]] == hash_map1[s[j]]:
                form += 1
            while form == req:
                cur_len = j-i+1
                if cur_len < min_len:
                    min_len = cur_len
                    res = s[i:j+1]
                hash_map2[s[i]] -= 1
                if hash_map2[s[i]] < hash_map1[s[i]]:
                    form -= 1
                
                i += 1
        return res


            

            


        