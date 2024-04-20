class Solution {
public:
    void dfs(vector<vector<int>>&g,int i,int j,int n,int m,int &x1,int &y1,int &x2,int &y2)
    {
        if(i < 0 || i >= n || j < 0 || j >= m)
        {
            return;
        }
        if(g[i][j] == 0)
        {
            return;
        }
        g[i][j] = 0;
        dfs(g,i+1,j,n,m,x1,y1,x2,y2);
        dfs(g,i-1,j,n,m,x1,y1,x2,y2);
        dfs(g,i,j+1,n,m,x1,y1,x2,y2);
        dfs(g,i,j-1,n,m,x1,y1,x2,y2);
        x1 = min(x1,i);
        y1 = min(y1,j);
        x2 = max(x2,i);
        y2 = max(y2,j);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
       vector<vector<int>>res;
        
        int n = land.size();
        int m = land[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(land[i][j])
                {
                   int x1 = i;
                    int y1 = j;
                    int x2 = i;
                    int y2 = j;
                    dfs(land,i,j,n,m,x1,y1,x2,y2);
                    res.push_back({x1,y1,x2,y2});
                }
            }
        }
        return res;
    }
};
