class Solution {
public:
    bool isValid(int i,int j,int n,int m,vector<vector<int>>&grid)
    {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1)
        {
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {       
        queue<pair<int,int>>q;
        int fresh = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        if(fresh == 0){
            return 0;
        }
        
        vector<pair<int,int>>dirs = {{0,1},{0,-1},{-1,0},{1,0}};
        int minutes = 0;
        while(!q.empty())
        {
            int sz = q.size();
            bool rott = false;
            while(sz--)
            {
                
                auto [x,y] = q.front();
                q.pop();
                for(auto d:dirs)
                {
                    int dx = x+d.first;
                    int dy = y+d.second;

                    if(isValid(dx,dy,n,m,grid))
                    {
                        grid[dx][dy] = 2;
                        q.push({dx,dy});
                        fresh--;
                        rott = true;
                    }
                }
                
            }
            if(rott) minutes++;
           
        }
        return fresh == 0 ? minutes : -1;
    }
};