class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dup(n,vector<int>(m,0));

        int k = 0;
        int l = 0;
        for(int i=0;i<m;i++)
        {
            k = 0;
            for(int j=n-1;j>=0;j--)
            {
                dup[l][k] = matrix[j][i];
                k++;
            }
            l++;
        }
        matrix = dup;
    }
};