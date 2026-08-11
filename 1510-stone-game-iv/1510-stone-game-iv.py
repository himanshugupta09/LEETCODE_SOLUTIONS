from functools import cache
class Solution:
    def winnerSquareGame(self, n: int) -> bool:       
        @cache
        def dp(n):
            if n == 0:
                return False
            x = 1
            while x*x <= n:
                took = dp(n-x*x)
                if took == False:
                    return True
                x += 1
            return False
        return dp(n)
                