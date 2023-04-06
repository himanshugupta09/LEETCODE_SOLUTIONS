class Solution {
public:

    bool bfs(int x,int y,int n,int m,vector<vector<int>>& grid,vector<vector<bool>>& vis)
    {
        queue<pair<int,int>>q;
        q.push({x,y});

        vis[x][y] = 2;
        bool close = true;

        vector<int>dix{0,1,0,-1};
        vector<int>diy{-1,0,1,0};

        while(!q.empty())
        {
            x = q.front().first;
            y = q.front().second;

            q.pop();

            for(int i=0;i<4;i++)
            {
                int r = x+dix[i];
                int c = y+diy[i];

                if(r<0 || r>=n || c < 0 || c>=m)
                {
                    close = false;
                }
                else if(grid[r][c] == 0 && !vis[r][c])
                {
                    q.push({r,c});
                    vis[r][c] = true;
                }
            }
        }
        return close;
    }

    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m));

        int res = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0 && !vis[i][j] && bfs(i,j,n,m,grid,vis))
                {
                    res++;
                }
            }
        }
        return res;
    }
};
