class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n  = matrix.size();
        int m = matrix[0].size();

        vector<bool>rowflag(n,false);
        vector<bool>colflag(m,false);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    rowflag[i] = true;
                    colflag[j] = true;
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            if(colflag[i] == true)
            {
                for(int j=0;j<n;j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(rowflag[i] == true)
            {
                for(int j=0;j<m;j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};