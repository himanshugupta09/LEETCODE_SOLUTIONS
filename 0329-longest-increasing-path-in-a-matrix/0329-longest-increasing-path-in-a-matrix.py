from functools import cache
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        m = len(matrix[0])
        path_length = 1
        def isValid(i,j):
            if i > n-1 or i < 0 or j > m-1 or j < 0:
                return False
            return True
        @cache
        def dfs(i,j):
            res = 1
            up = matrix[i-1][j] if isValid(i-1,j) else 0
            down = matrix[i+1][j] if isValid(i+1,j) else 0
            left = matrix[i][j-1] if isValid(i,j-1) else 0
            right = matrix[i][j+1] if isValid(i,j+1) else 0
            if matrix[i][j] < up:
                res = max(res,1 + dfs(i-1,j))
            if matrix[i][j] < down:
                res = max(res,1 + dfs(i+1,j))
            if matrix[i][j] < left:
                res = max(res,1 + dfs(i,j-1))
            if matrix[i][j] < right:
                res = max(res,1 + dfs(i,j+1))
            return res
        for i in range(n):
            for j in range(m):
                res = dfs(i,j)
                path_length = max(path_length,res)
        return path_length