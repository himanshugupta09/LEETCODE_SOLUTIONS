from functools import cache
class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        max_alice = 0
        suffix = [0]*(n)
        suffix[-1] = piles[-1]
        for i in range(n-2,-1,-1):
            suffix[i] = piles[i]+suffix[i+1]
        @cache
        def dp(i,M):
            max_score = 0
            if i == n:
                return 0
            for X in range(1,2*M+1):
                if i+X <= n:
                    bob_take = dp(i+X,max(M,X))
                    alice_take = suffix[i]-bob_take
                    max_score = max(max_score,alice_take)
            return max_score
        

        return dp(0,1)

        
