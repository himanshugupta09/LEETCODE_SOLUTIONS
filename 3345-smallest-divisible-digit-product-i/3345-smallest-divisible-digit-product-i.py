class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        def digProd(num):
            res = 1
            while num:
                res *= num%10
                num //= 10
            return res
        for i in range(n,n+11):
            dig = digProd(i)
            if dig%t == 0:
                return i
        
        