class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        onesrow = [0 for i  in range(len(grid))]
        onescol = [0 for i in range(len(grid[0]))]
        zerows = [0 for i  in range(len(grid))]
        zerocol = [0 for i in range(len(grid[0]))]
        
        for i in range(len(grid)):
            onesrow[i] = grid[i].count(1)
        
        for i in range(len(grid)):
            zerows[i] = grid[i].count(0)
        
        for i in range(len(grid[0])):
            t = 0
            for j in range(len(grid)):
                if grid[j][i] == 0:
                    t += 1
            zerocol[i] = t
            
        for i in range(len(grid[0])):
            t = 0
            for j in range(len(grid)):
                if grid[j][i] == 1:
                    t += 1
            onescol[i] = t
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                sm = onesrow[i] + onescol[j] - zerows[i]-zerocol[j]
                grid[i][j] = sm
        return grid
        
            
