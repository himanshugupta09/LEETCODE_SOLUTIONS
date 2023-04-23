class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        md = 10**9+7
        n = len(s);
        
        dp = [1] + [0]*n

        for i in range(n):
            if s[i] == '0':
                continue

            for j in range(i,n):
                cur = s[i:j+1]

                if int(cur)>k:
                    break
                dp[j+1] += dp[i]
                dp[j+1] %= md
        return dp[-1]            

