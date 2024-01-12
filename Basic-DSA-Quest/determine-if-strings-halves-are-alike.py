class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vo = "aeiouAEIOU"
        
        cn1 = 0
        cn2 = 0
        for i in range(0,len(s)//2):
            if s[i] in vo:
                cn1 += 1
        for i in range(len(s)//2,len(s)):
            if s[i] in vo:
                cn2 += 1
        return cn1 == cn2
        
