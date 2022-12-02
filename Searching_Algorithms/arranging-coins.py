class Solution:
    def arrangeCoins(self, n: int) -> int:
        l,r = 0,n
        while l<=r:
            k = (r+l)//2
            cur = k*(k+1)//2
            if cur == n:
                return k
            if n<cur:
                r = k-1
            else:
                l = k+1
        return r       
        
