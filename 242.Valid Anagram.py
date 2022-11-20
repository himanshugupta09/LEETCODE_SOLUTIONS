class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        d = {}
        e = {}
        n1 = len(s)
        n2 = len(t)
        if n1!=n2:
            return False
        else:
            for i in range(0,n1):
                if s[i] in d:
                    d[s[i]]+=1
                else:
                    d[s[i]] = 1
                    
            for i in range(0,n2):
                if t[i] in e:
                    e[t[i]]+=1
                else:
                    e[t[i]] = 1        
            if d == e:
                return  True
            else:
                return False
        
