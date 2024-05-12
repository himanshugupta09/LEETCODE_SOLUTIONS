class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int r1 = 0;
        int r2 = 2;
        int c1;
        int c2;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>res;
        
        while(r2 < n)
        {
            vector<int>t;
            c2 = 2;
            c1 = 0;
            while(c2 < m)
            {
                int mx = INT_MIN;
                for(int i=r1;i<=r2;i++)
                {
                    for(int j=c1;j<=c2;j++)
                    {
                        mx = max(mx,grid[i][j]);
                    }
                }
                t.push_back(mx);
                c2++;
                c1++;
            }
            res.push_back(t);
            r1++;
            r2++;
        }
        return res;
    }
};
