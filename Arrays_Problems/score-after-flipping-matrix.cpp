class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        
        for(int i=0;i<n;i++)
        {
            if(grid[i][0] == 0)
            {
                for(int j=0;j<m;j++)
                {
                    
                    grid[i][j] = 1-grid[i][j];
                }
            }
           
        }
        for(int i=1;i<m;i++)
        {
            int zc=0;
            for(int j=0;j<n;j++)
            {
                if(grid[j][i]==0)
                {
                    
                    zc++;
                }
            }
            if(zc > n-zc)
            {
                for(int j=0;j<n;j++)
                {
                    grid[j][i]=1-grid[j][i];
                }
            }
            
        }
        int res = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int rc = grid[i][j] << (m-j-1);
                res += rc;
            }
        }
        return res;
    }
};
