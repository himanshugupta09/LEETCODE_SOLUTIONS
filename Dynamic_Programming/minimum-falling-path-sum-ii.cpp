class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int mini = INT_MAX;
                for(int k=0;k<n;k++)
                {
                    if(k != j) mini = min(mini,grid[i-1][k]);
                }
                grid[i][j] += mini;
            }
        }
        int res = INT_MAX;
        for(int i=0;i<n;i++)
        {
            res = min(res,grid[n-1][i]);
        }
        return res;
    }
};
