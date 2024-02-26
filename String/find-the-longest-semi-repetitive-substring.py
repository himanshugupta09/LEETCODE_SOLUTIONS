class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        res = ''
        ls = 0
        
        for   i in range(len(s)):
            tmp = s[i]
            j = i+1
            doble = 0
            while j < len(s) and doble < 2:
                if s[j] == tmp[-1] and doble== 0:
                    doble += 1
                    tmp += s[j]
                elif s[j] == tmp[-1] and doble == 1:
                    break
                elif s[j] != tmp[-1]:
                    tmp += s[j]
                    
                j += 1
            if len(tmp) > len(res):
                res = tmp
        return len(res)
                    
            
        
