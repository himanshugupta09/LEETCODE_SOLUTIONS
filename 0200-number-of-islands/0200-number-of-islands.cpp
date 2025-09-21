class Solution {
public:
    void bfs(vector<vector<char>>&grid,int n,int m,int i,int j)
    {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1')
        {
            return;
        }
        grid[i][j] = '0';
        bfs(grid,n,m,i+1,j);
        bfs(grid,n,m,i-1,j);
        bfs(grid,n,m,i,j-1);
        bfs(grid,n,m,i,j+1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int nums = 0;
        //char col = 'a';
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1')
                {
                    nums++;
                    bfs(grid,n,m,i,j);
                }
            }
        }
        return nums;

    }
};