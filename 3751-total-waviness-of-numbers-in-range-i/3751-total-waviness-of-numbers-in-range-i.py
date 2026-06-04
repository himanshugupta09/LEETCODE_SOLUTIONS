class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        def wavy(n:int) -> int:
            s = str(n)
            return sum(
                (a < b > c) or (a > b < c) for a,b,c in zip(s,s[1:],s[2:])
            )
        return sum(wavy(n) for n in range(num1,num2+1))
        
        