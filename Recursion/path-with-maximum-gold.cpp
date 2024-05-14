class Solution {
public:
    int getSum(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }
        int nc = grid[i][j];
        visited[i][j] = true; // Mark as visited
        int csm = nc + max({getSum(i + 1, j, n, m, grid, visited),
                            getSum(i - 1, j, n, m, grid, visited),
                            getSum(i, j - 1, n, m, grid, visited),
                            getSum(i, j + 1, n, m, grid, visited)});
        visited[i][j] = false; // Mark as unvisited
        return csm;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int maxSum = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    maxSum = max(maxSum, getSum(i, j, n, m, grid, visited));
                }
            }
        }
        return maxSum;
    }
};
