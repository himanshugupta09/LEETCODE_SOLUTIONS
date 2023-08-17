class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX-10000));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                }
                else
                {
                    if(i > 0)
                    {
                        dist[i][j] = min(dist[i-1][j]+1,dist[i][j]);
                    }
                    if(j > 0)
                    {
                        dist[i][j] = min(dist[i][j-1]+1,dist[i][j]);
                    }
                   
                }
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j = m-1;j>=0;j--)
            {
                if(j+1 < m)
                {
                    dist[i][j] = min(dist[i][j+1]+1,dist[i][j]);
                        
                }
                if(i+1 < n)
                {
                    dist[i][j] = min(dist[i][j],dist[i+1][j]+1);

                }

                
            }
        }
        return dist;

        
    }
};
