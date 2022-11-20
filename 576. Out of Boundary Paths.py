class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        
        dp = [[[-1 for _ in range(51)] for l in range(51)] for i in range(51)]
        
        def solve(m,n,maxMove,sr,sc):
            if sr>=m or sr<0 or sc>=n or sc<0:
                return 1
            if maxMove<=0:
                return 0
            if dp[sr][sc][maxMove]!= -1:
                return dp[sr][sc][maxMove]
            cnt = 0
            cnt+= solve(m,n,maxMove-1,sr-1,sc)
            cnt+= solve(m,n,maxMove-1,sr+1,sc)
            cnt+= solve(m,n,maxMove-1,sr,sc-1)
            cnt+= solve(m,n,maxMove-1,sr,sc+1)
            dp[sr][sc][maxMove] = cnt
            return dp[sr][sc][maxMove]%1000000007
        
        return (solve(m,n,maxMove,startRow,startColumn)%1000000007)
