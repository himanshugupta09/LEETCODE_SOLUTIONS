class Solution {
public:
    const pair<int,int> direction[4] = {{-1,0},{1,0},{0,-1},{0,1}};
    int maxDistance(vector<vector<int>>& grid) {
        
        int visited[grid.size()][grid[0].size()];

        queue<pair<int,int>>q;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                visited[i][j] = grid[i][j];
                if(grid[i][j])
                {
                    q.push({i,j});
                }
            }
        }

        int dist = -1;

        while(!q.empty())
        {
            int qs = q.size();

            while(qs--)
            {
                pair<int,int>lnd = q.front();
                q.pop();

                for (pair<int, int> dir : direction) {
                    int x = lnd.first + dir.first;
                    int y = lnd.second + dir.second;
                    
                    if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && visited[x][y] == 0) {

                        visited[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }

            dist++;
        }

        return dist == 0?-1:dist;

    }
};
