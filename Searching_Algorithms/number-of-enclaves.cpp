class Solution {
public:

    void bfs(int x,int y,int n,int m,vector<vector<bool>>& vis,vector<vector<int>>& grid)
    {
        queue<pair<int,int>>q;
        q.push({x,y});
        vis[x][y] = 2;

        while(!q.empty())
        {
            x = q.front().first;
            y = q.front().second;

            q.pop();
        vector<int> dirx{0, 1, 0, -1};
        vector<int> diry{-1, 0, 1, 0};

            for(int i=0;i<4;i++)
            {
                int r = x+dirx[i];
                int c = y+diry[i];

                if(r < 0 || r>= n || c < 0 || c >= m)
                {
                    continue;
                }
                else if(grid[r][c] == 1 && !vis[r][c])
                {
                    q.push({r,c});
                    vis[r][c] = true;
                }
            }
        }
        return;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m));
        int res = 0;

        for(int i=0;i<n;i++)
        {
            if(grid[i][0] == 1 && !vis[i][0])
            {

                bfs(i,0,n,m,vis,grid);
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1])
            {
                bfs(i,m-1,n,m,vis,grid);
            }
        }

        for(int i=0;i<m;i++)
        {
            if(grid[0][i] == 1 && !vis[0][i])
            {
                bfs(0,i,n,m,vis,grid);
            }
            if(grid[n-1][i] == 1 && !vis[n-1][i])
            {
                bfs(n-1,i,n,m,vis,grid);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                {
                    res++;
                }
            }
        }

        return res;



    }
};
