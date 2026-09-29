class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        vector<vector<int>> vis(n, vector<int>(n, 0));

        int sx = knightPos[0] - 1;
        int sy = knightPos[1] - 1;
        int tx = targetPos[0] - 1;
        int ty = targetPos[1] - 1;

        vector<pair<int,int>> dirs = {
            {2,1}, {2,-1}, {-2,1}, {-2,-1},
            {1,2}, {1,-2}, {-1,2}, {-1,-2}
        };

        queue<pair<pair<int,int>, int>> q;

        q.push({{sx, sy}, 0});
        vis[sx][sy] = 1;

        while (!q.empty()) {
            auto [pos, steps] = q.front();
            q.pop();

            int x = pos.first;
            int y = pos.second;

            if (x == tx && y == ty)
                return steps;

            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < n &&
                    ny >= 0 && ny < n &&
                    !vis[nx][ny]) {

                    vis[nx][ny] = 1;
                    q.push({{nx, ny}, steps + 1});
                }
            }
        }

        return -1;
        
    }
};