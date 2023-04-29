class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        res = []
        
        for i in range(len(A)):
            commn = len(set(A[:i+1]).intersection(set(B[:i+1])))
            res.append(commn)
        return res    
        
