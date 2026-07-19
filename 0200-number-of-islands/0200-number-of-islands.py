class Solution:
    def dfs(self,grid:List[List[str]], vis:[List[List[int]]],n:int,m:int,x:int,y:int) -> int:
        if x >= n or y >= m or x < 0 or y < 0:
            return 0
        if grid[x][y] == "0" or vis[x][y] == 1:
            return 0
        vis[x][y] = 1
        return (1 + 
                self.dfs(grid, vis, n, m, x + 1, y) + 
                self.dfs(grid, vis, n, m, x - 1, y) + 
                self.dfs(grid, vis, n, m, x, y + 1) + 
                self.dfs(grid, vis, n, m, x, y - 1))
    def numIslands(self, grid: List[List[str]]) -> int:
        islands_count = 0
        n = len(grid)
        m = len(grid[0])
        vis = [[0 for _ in range(m)] for _ in range(n)]
        for i in range(n):
            for j in range(m):
                size = self.dfs(grid,vis,n,m,i,j)
                if size > 0:
                    islands_count += 1
        return islands_count
        