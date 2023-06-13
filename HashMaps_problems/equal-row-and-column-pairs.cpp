class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int>mp;
        int res = 0;
        int n = grid.size();
        for(int i=0;i<n;i++)
        {
            string temp = "";
            for(int j=0;j<n;j++)
            {
                temp += to_string(grid[i][j]) + "#";
            }
            mp[temp]++;
        }

        for(int i=0;i<n;i++)
        {
            string temp = "";
            for(int j=0;j<n;j++)
            {
                temp += to_string(grid[j][i]) + "#";
            }
            res += mp[temp];
        }

        // for(auto i:mp)
        // {
        //     res += i.second;
        // }
        return res;
    }
};
