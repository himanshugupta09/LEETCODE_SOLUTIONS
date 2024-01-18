class Solution:
    def climbStairs(self, n: int) -> int:
        a = 1
        b = 1
        c = a+b
        if n == 1:
            return 1
        elif n == 2:
            return 2
        else:
            for i in range(3,n+1):
                a = b
                b = c
                c = a+b
            return c
        
