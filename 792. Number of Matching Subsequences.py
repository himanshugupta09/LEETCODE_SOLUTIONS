class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        Map = defaultdict(list)
        ans = 0
        
        for i,j in enumerate(s):
            Map[j].append(i)
            
        
        for k in words:
            prev = -1
            found = True
            for  i in k:
                tmp = bisect.bisect(Map[i],prev)
                if tmp == len(Map[i]):
                    found = False
                    break
                else:
                    prev = Map[i][tmp]
            if found:
                ans+=1
        return ans       
