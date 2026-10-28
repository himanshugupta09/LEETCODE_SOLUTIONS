class Solution:
    def subarrayXor(self, arr, m):
        # code here
        cur_xor = 0
        res = 0
        mp = {0:1}

        
        for i in arr:
            cur_xor = cur_xor^i
            res += mp.get(cur_xor^m,0)
            mp[cur_xor] = mp.get(cur_xor, 0) + 1
        return res