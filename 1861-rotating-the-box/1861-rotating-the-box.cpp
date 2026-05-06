class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>>result(n,vector<char>(m,'.'));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                result[j][i] = boxGrid[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(result[i].begin(),result[i].end());
        }
        for(int j=0;j<m;j++)
        {
            int lowestRow = n-1;
            for(int i=n-1;i>=0;i--)
            {
                if(result[i][j] == '#')
                {
                    result[i][j] = '.';
                    result[lowestRow][j] = '#';
                    lowestRow--;
                }
                if(result[i][j] == '*')
                {
                    lowestRow = i-1;
                }
            }
        }
        return result;
    }
};