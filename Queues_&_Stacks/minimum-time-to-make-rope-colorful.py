class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        stk  = []
        res = 0
        
        i = 0
        while i < len(colors):
            if len(stk) == 0:
                stk.append([colors[i],neededTime[i]])
            else:
                col,nd  = stk[-1][0],stk[-1][1]
                if colors[i] == col and neededTime[i] > nd:
                    stk.pop()
                    res += nd
                    stk.append([colors[i],neededTime[i]])
                elif colors[i] == col and neededTime[i] <= nd:
                    res += neededTime[i]
                else:
                    stk.append([colors[i],neededTime[i]])
            i += 1
        del stk
        return res
                    
                
