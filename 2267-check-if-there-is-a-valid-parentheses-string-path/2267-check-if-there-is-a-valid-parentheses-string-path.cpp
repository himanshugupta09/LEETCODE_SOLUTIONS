class Solution {
public:
    // Returns true if OUT of bounds
    bool isValid(int x, int y, int n, int m) {
        return (x < 0 || y < 0 || x >= n || y >= m);
    }

    bool solve(vector<vector<vector<int>>>& dp, vector<vector<char>>& grid, int x, int y, int n, int m,int bal) {
        // 1. Bounds check: If we step out of bounds, path is invalid
        if(isValid(x, y, n, m)){ 
            return false;
        }
        if(dp[x][y][bal] != -1) {
            return dp[x][y][bal];
        }
        int currbal = bal;
        if(currbal < 0)
        {
            return false;
        }
        // 2. Process the current cell
        char curr = grid[x][y];
        if(curr == '(') {
            currbal++; // ADDED: Actually push opening brackets to the stack
        } else if (curr == ')') {
            if(!bal){
                return false; // Fails if we try to close an empty stack
            }
            currbal--; // Matches and removes an opening bracket
        }

        // 3. Win Condition: Reached the bottom-right corner
        if(x == n - 1 && y == m - 1) {
            return dp[x][y][bal] = (currbal == 0); 
        }

        // 4. Continue DFS traversal
        bool down = solve(dp, grid, x + 1, y, n, m, currbal);
        bool right = solve(dp, grid, x, y + 1, n, m, currbal);
        return dp[x][y][bal] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int stk = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(n + m, -1)));
        int bal = 0;
        return solve(dp, grid, 0, 0, n, m,bal);
    }
};