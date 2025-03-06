class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mpp[grid[i][j]]++;
            }
        }
        int mis = 0,rep = 0;
        for(int i=1;i<=n*n;i++)
        {
            if(!mpp.count(i))
            {
                mis = i;
            }
            else if(mpp[i] == 2)
            {
                rep = i;
            }
        }
        return {rep,mis};
    }
};