class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int r,c;
        r = mat.size();
        c = mat[0].size();
        int prefix[r+1][c];
        prefix[r-1][c-1] = mat[r-1][c-1];
        prefix[r][c-1] = 0;
        for(int i = c-2 ; i >= 0 ; i--)
        {
            prefix[r-1][i] = prefix[r-1][i+1] + mat[r-1][i];
            prefix[r][i] = 0;
        }
        for(int j = r-2 ; j >= 0 ; j--)
            prefix[j][c-1] = prefix[j+1][c-1] + mat[j][c-1];
        for(int i = r-2 ; i >= 0 ; i--)
            for(int j = c-2 ; j >= 0 ;j--)
                prefix[i][j] = prefix[i+1][j] + prefix[i][j+1] - prefix[i+1][j+1] + mat[i][j];
      
        int cnt = 0;
        for(int i = 0 ; i < r ; i++)
        {
            for(int j = i+1; j <= r ; j++)
            {
                map<int , int> mp;
                mp[0] = 1;
                for(int k = c-1 ; k >= 0 ; k--)
                {
                    int sum = prefix[i][k] - prefix[j][k];
                    int reqSum = sum - target;
                    cnt += mp[reqSum];
                    mp[sum]++;
                }
            }
        }
        return cnt;
    }
};
