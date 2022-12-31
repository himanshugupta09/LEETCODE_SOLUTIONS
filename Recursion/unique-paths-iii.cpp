class Solution {
public:
    
    
    
    int traverse(vector<vector<int>>& grid,int x,int y,int zc)
    {
       if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1)
       {
           return 0;
       }
       if(grid[x][y] == 2)
       {
           return zc == -1?1:0;
       }
       grid[x][y] = -1;
       zc--;

       int totP = traverse(grid,x+1,y,zc) + traverse(grid,x-1,y,zc) + traverse(grid,x,y+1,zc) + traverse(grid,x,y-1,zc);
       grid[x][y] = 0;
       zc++;

       return totP;

       
    }
    int uniquePathsIII(vector<vector<int>>& grid) {

            int zc = 0;
            int sx = 0;
            int sy = 0;

            for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                {
                    if(grid[i][j] == 0)
                    {
                        zc++;
                    }
                    else if(grid[i][j] == 1)
                    {
                        sx = i;
                        sy = j;
                    }
                }
            }

            return traverse(grid,sx,sy,zc);
    }
};
