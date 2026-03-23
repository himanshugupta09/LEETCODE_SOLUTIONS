from collections import deque
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def is_valid(n,m,row,col,grid):
            if row < 0 or col < 0 or row >= n or col >= m or grid[row][col] == "0":
                return False
            return True

        
        cords = [[0,1],[1,0],[-1,0],[0,-1]]
        islands = 0
        n = len(grid)
        m = len(grid[0])
        for i in range(n):
            for j in range(m):
                if grid[i][j] == "1":
                    islands += 1
                    queue = deque([])
                    queue.append([i,j])
                    while len(queue) > 0:
                        x,y = queue.popleft()
                        
                        
                        for delx,dely in cords:
                            new_x = int(x)+delx
                            new_y = int(y)+dely
                            if is_valid(n,m,new_x,new_y,grid):
                                grid[new_x][new_y] = "0"
                                queue.append([new_x,new_y])
        return islands
                    
                            



        