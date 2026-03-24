from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        cords = [[0,1],[1,0],[-1,0],[0,-1]]
        
        def isValid(grid, n, m, i, j):
            return 0 <= i < n and 0 <= j < m and grid[i][j] == 1
        
        time = 0
        n = len(grid)
        m = len(grid[0])
        rotten = deque([])
        fresh = 0
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    rotten.append([i, j])
                elif grid[i][j] == 1:
                    fresh += 1
        
        # Edge case
        if fresh == 0:
            return 0
        
        while rotten:
            size = len(rotten)
            infected = False
            
            for _ in range(size):
                x, y = rotten.popleft()
                
                for delx, dely in cords:
                    new_x = x + delx
                    new_y = y + dely
                    
                    if isValid(grid, n, m, new_x, new_y):
                        grid[new_x][new_y] = 2
                        fresh -= 1
                        rotten.append([new_x, new_y])
                        infected = True
            
            if infected:
                time += 1
        
        return time if fresh == 0 else -1