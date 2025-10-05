class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        pac = set()
        atl = set()
        q1 = []
        q2 = []
        n = len(heights)
        m = len(heights[0])
        for i in range(n):
            for j in range(m):
                if i == 0 or j == 0:
                    pac.add((i,j))
                    q1.append((i,j))
                if i == n-1 or j == m-1:
                    atl.add((i,j))
                    q2.append((i,j))
        def bfs(q,vis):
            while q:
                for _ in range(len(q)):
                    i,j = q.pop(0)
                    for a,b in [[0, -1], [0, 1], [1, 0], [-1, 0]]:
                        x = i+a
                        y = j+b
                        if (0 <= x < n and 0 <= y < m and (x, y) not in vis and heights[x][y] >= heights[i][j]):
                            vis.add((x, y))
                            q.append((x, y))
        bfs(q1,pac)
        bfs(q2,atl)
        return [(i, j) for i in range(n) for j in range(m) if (i, j) in pac and (i, j) in atl]
        