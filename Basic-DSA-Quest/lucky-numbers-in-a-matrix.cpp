class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        vector<int>minRows;
        vector<int>maxCols;
        int n = matrix.size();
        int m  = matrix[0].size();
        
        for(int i=0;i<n;i++)
        {
            int mini = INT_MAX;
            for(int j=0;j<m;j++)
            {
                mini = min(mini,matrix[i][j]);
            }
            minRows.push_back(mini);
        }
        for(int i=0;i<m;i++)
        {
            int maxi = INT_MIN;
            for(int j=0;j<n;j++)
            {
                maxi = max(maxi,matrix[j][i]);
            }
            maxCols.push_back(maxi);
        }
        vector<int>res;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int mr = minRows[i];
                int mc = maxCols[j];
                
                if(matrix[i][j] == mr && matrix[i][j] == mc)
                {
                    res.push_back(matrix[i][j]);
                }
            }
        }
        return res;
    }
};
