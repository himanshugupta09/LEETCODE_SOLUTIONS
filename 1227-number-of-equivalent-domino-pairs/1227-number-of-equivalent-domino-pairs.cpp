class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        vector<int>num(100);
        for(auto it:dominoes)
        {
            int val = it[0] < it[1] ? it[0]*10+it[1] : it[1]*10+it[0];
            res += num[val];
            num[val]++; 
        }
        return res;
    }
};