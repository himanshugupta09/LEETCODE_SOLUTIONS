/*
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        int idx = -1;
        int res = 0;
        vector<int> cnts(n + 2, 0); // Increased size to safely handle indices from 0 to n+1

        for (int i = 0; i < n; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            if (u >= 0 && u <= n + 1) {
                cnts[u]++;
            }
            if (v >= 0 && v <= n + 1) {
                cnts[v]++;
            }
        }

        for (int i = 0; i <= n + 1; ++i) {
            if (cnts[i] > res) {
                idx = i;
                res = cnts[i];
            }
        }

        return idx;
    }
};

*/
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int>fe = edges[0];
        vector<int>se = edges[1];
        
        return (fe[0] == se[0] || fe[0] == se[1]) ? fe[0] : fe[1];
    }
};
