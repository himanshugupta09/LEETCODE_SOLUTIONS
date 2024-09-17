class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        w1 = s1.split(' ')
        w2 = s2.split(' ')
        mp1 = Counter(w1)
        mp2 = Counter(w2)
        
        
        res = []
        for key,val in mp1.items():
            if val == 1 and key not in mp2:
                res.append(key)
        for key,val in mp2.items():
            if val == 1 and key not in mp1:
                res.append(key)
        return res
