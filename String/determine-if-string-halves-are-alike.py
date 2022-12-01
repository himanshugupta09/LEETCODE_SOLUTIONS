class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        a = s[0:len(s)//2]
        b = s[len(s)//2:]
        vowels = ['a','e','i','o','u','A','E','I','O','U']
        v1 = 0
        v2 = 0
        for i in a:
            if i in vowels:
                v1+=1
            
                
        for i in b:
            if i in vowels:
                v2+=1
                
        if v1==v2:
            return True
        else:
            return False
                
                
        
