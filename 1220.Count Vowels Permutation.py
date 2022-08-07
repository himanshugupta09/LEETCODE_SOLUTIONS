class Solution:
    def countVowelPermutation(self, n: int) -> int:
        md = 10**9 + 7
        a,e,i,o,u = 1,1,1,1,1
        a2,e2,i2,o2,u2 = 0,0,0,0,0
        
        for k in range(2,n+1):
            a2 = (e + i + u)%md
            e2 = (a + i)%md
            i2 = (e + o)%md
            o2 = i
            u2 = (o + i)%md
            a,e,i,o,u = a2,e2,i2,o2,u2
        
        return (a+e+i+o+u)%md
