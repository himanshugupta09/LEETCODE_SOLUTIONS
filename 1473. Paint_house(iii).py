# Below here first Approach that is shared is Optimized DP Bottom Up Approach
class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        
        Max_cost = 1000001
        
        pmemo = [[Max_cost for j in range(n)] for i in range(target)]
        
        
        for color in range(1,n+1):
            if houses[0] == color:
                pmemo[1][color-1] = 0
            elif not(houses[0]):
                pmemo[1][color-1] = cost[0][color-1]
                
        
        for i in range(1,m):
            memo = [[Max_cost for j in range(n)] for i in range(target+1)]
            
            
            for j in range(1,min(target,i+1)+1):
                for k in range(1,n+1):
                    if houses[i] and k != houses[i]:
                        continue
                    currCost = Max_cost
                    for prevcol in range(1,n+1):
                        if prevcol != k:
                            currCost = min(currCost,pmemo[j-1][prevcol-1])
                        else:
                            currCost = min(currCost,pmemo[j][k-1])
                            
                    costToPaint = 0 if houses[i] else cost[i][k-1]
                    memo[j][k-1] = currCost+costToPaint
                    
            pmemo = memo
            
        min_cost = Max_cost
        for color in range(1,n+1):
            min_cost = min(min_cost,pmemo[target][color-1])
        return -1 if min_cost == Max_cost else min_cost
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#-=============================================================================================================================================================================

# Now Another Appraoch with DFS 
class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        @lru_cache(None)
        
        def DFS(i,target_left,k=0):
            if target_left > m-i:
                return -1
            if i==m:
                return 0 if target_left == 0 else -1
            
            if houses[i] != 0:
                return DFS(i+1,target_left-int(houses[i]!=k),houses[i])
            else:
                ret = []
                for j in range(1,n+1):
                    currcost = cost[i][j-1]
                    com_cost = DFS(i+1,target_left-int(j!=k),j)
                    if com_cost != -1:
                        ret.append(currcost+com_cost)
                return min(ret) if ret else -1
            
        return DFS(0,target)            
            
        
        
        
        
