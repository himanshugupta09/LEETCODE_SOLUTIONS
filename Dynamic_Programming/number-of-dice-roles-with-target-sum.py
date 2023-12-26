mod = 10**9+7
class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        dp = [[0 for i in range(target+1)] for j in range(n+1)]
        
        dp[0][0] = 1
        
        for i in range(1,n+1):
            for j in range(i,min(k*i,target)+1):
                if i == 1:
                    dp[i][j] = 1
                else:
                    en = j-1
                    st = max(1,j-k)
                    dp[i][j] = sum(dp[i-1][st:en+1])
                    
        #print(dp)
        return dp[n][target]%mod
                    
