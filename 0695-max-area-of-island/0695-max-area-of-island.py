class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        max_area = 0
        def bfs(grid,i,j,n,m,visited):
            if i < 0 or i >= n or j < 0 or j >= m or grid[i][j] == 0 or visited[i][j]:
                return 0
            visited[i][j] = True
            return 1 + bfs(grid,i+1,j,n,m,visited) + bfs(grid,i-1,j,n,m,visited) + \
            bfs(grid,i,j+1,n,m,visited) + bfs(grid,i,j-1,n,m,visited)
            
        n = len(grid)
        m = len(grid[0])
        visited = [[False] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                if grid[i][j] and not visited[i][j]:
                    area = bfs(grid,i,j,n,m,visited)
                    max_area = max(max_area,area)
        return max_area