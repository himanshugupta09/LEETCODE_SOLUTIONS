//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}

void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int i, int j, int n, int m) {
    vis[i][j] = 1;

    for (int x = 0; x < 8; x++) {
        int dx = i + dirs[x][0];
        int dy = j + dirs[x][1];

        if (isValid(dx, dy, n, m) && (grid[dx][dy] == '1' && !vis[dx][dy])) {
            bfs(grid, vis, dx, dy, n, m);
        }
    }
}

int numIslands(vector<vector<char>> &grid) {
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1' && (!vis[i][j])) {
                res++;
                bfs(grid, vis, i, j, n, m);
            }
        }
    }
    return res;
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
