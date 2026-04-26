class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        def dsu_find(dsu,x):
            dsu[x] = x if x==dsu[x]  else dsu_find(dsu,dsu[x])
            return   dsu[x]
        def dsu_join(dsu,x,y):
            mn,mx = (x,y) if x%2==0  else (y,x)
            dsu[dsu_find(dsu,mx)] = dsu_find(dsu,mn)
        
        m,n = len(grid), len(grid[0])
        dsu = [i*n +j  for i,j in product(range(m), range(n))]

        for i,j in product(range(m), range(n)):
            if  i and j and grid[i-1][j] == grid[i][j] == grid[i][j-1] and \
                dsu_find(dsu, (i-1)*n+j) == dsu_find(dsu, i*n +(j-1)):
                return  True
            if  i and grid[i-1][j] == grid[i][j]: dsu_join(dsu, (i-1)*n+j, i*n+j)
            if  j and grid[i][j-1] == grid[i][j]: dsu_join(dsu, i*n+(j-1), i*n+j)
        return  False