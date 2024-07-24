class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        def getNewKey(num,mapping):
            s = str(num)
            res = ''
            for i in s:
                res += str(mapping[int(i)])
            return int(res)
        mp = defaultdict(list)
        for num in nums:
            k = getNewKey(num,mapping)
            mp[k].append(num)
        sort_list = sorted(mp.items())
        res = []
        for i in range(len(sort_list)):
            key,ls = sort_list[i]
            res.extend(ls)
        return res
        
        
