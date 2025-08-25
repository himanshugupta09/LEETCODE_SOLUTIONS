class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        if not mat or not mat[0]:
            return []
        n,m = len(mat),len(mat[0])
        res,im = [],[]
        for d in range(n+m-1):
            im.clear()
            r,c = 0 if d < m else d-m+1,d if d < m else m-1

            while r < n and c > -1:
                im.append(mat[r][c])
                r += 1
                c -= 1
            if d%2 == 0:
                res.extend(im[::-1])
            else:
                res.extend(im)
        return res
        