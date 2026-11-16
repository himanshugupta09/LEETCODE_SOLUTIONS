class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            groups = []
            
            for i in range(0, len(s), k):
                chunk = s[i:i+k]
                groups.append(str(sum(int(d) for d in chunk)))
            
            s = ''.join(groups)
        
        return s
