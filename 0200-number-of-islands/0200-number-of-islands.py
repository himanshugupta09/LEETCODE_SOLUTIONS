from collections import deque
from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid or not grid[0]:
            return 0
            
        n = len(grid)
        m = len(grid[0])
        islands_count = 0
        
        # Defining directional offsets for cleaner neighbor checking (Down, Up, Right, Left)
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        for i in range(n):
            for j in range(m):
                # If we hit unvisited land, we found a new island
                if grid[i][j] == "1":
                    islands_count += 1
                    
                    # Start Iterative BFS to sink the entire island
                    queue = deque([(i, j)])
                    grid[i][j] = "0"  # Mark as visited instantly by mutating the input grid
                    
                    while queue:
                        curr_x, curr_y = queue.popleft()
                        
                        for dx, dy in directions:
                            nx, ny = curr_x + dx, curr_y + dy
                            
                            # Clean, structured boundary and land check
                            if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == "1":
                                queue.append((nx, ny))
                                grid[nx][ny] = "0"  # Sink it immediately to prevent duplicate queue additions
                                
        return islands_count