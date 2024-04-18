class Solution {
public:
    int bfs(int i,int j,int n,int m,vector<vector<int>>&grid)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
        return 1; 
        }
        if(grid[i][j] == -1)
        {
            return 0;
        }
        grid[i][j] = -1; 
    
        int perimeter = 0;
        perimeter += bfs(i - 1, j, n, m, grid); 
        perimeter += bfs(i + 1, j, n, m, grid); 
        perimeter += bfs(i, j - 1, n, m, grid); 
        perimeter += bfs(i, j + 1, n, m, grid); 

        return perimeter;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int res = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]) res  += bfs(i,j,n,m,grid);
            }
        }
        return res;
        
    }
};
