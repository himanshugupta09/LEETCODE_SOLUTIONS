class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        counts = []
       
        for tile in bank:
            tc = tile.count('1')
            if tc  > 0:
                counts.append(tc)
            
        res  = 0
        for i in range(len(counts)-1):
            res = res + counts[i]*counts[i+1]
        return res
        
        
        
