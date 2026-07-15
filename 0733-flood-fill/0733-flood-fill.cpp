class Solution {
public:
    bool isValid(int n,int m,int nr,int nc,vector<vector<int>>&image,int sCol,vector<vector<bool>>&vis)
    {
        if(nr < 0 || nr >= n || nc < 0 || nc >= m || image[nr][nc] != sCol || vis[nr][nc] == true)
        {
            return false;
        }
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int sCol = image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});

        vector<int>dx = {0,0,-1,1};
        vector<int>dy = {1,-1,0,0};
        int n = image.size();
        int m  = image[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        while(!q.empty())
        {
            int ln = q.size();
            for(int l=0;l<ln;l++)
            {
                auto [x,y] = q.front();
                q.pop();
                image[x][y] = color;
                vis[x][y] = true;
                for(int i=0;i<4;i++)
                {
                    int nr = x + dx[i];
                    int nc = y + dy[i];
                    if(isValid(n,m,nr,nc,image,sCol,vis)){
                        q.push({nr,nc});
                    }
                }
            }
        }
        return image;

    }
};