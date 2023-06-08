class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int res = 0;
        int  n = grid[0].size();

        for(auto& i:grid)
        {
            int id = upper_bound(i.begin(),i.end(),0,greater<int>()) - i.begin();

            res += (n-id);
        }
        return res;
        
    }
};
