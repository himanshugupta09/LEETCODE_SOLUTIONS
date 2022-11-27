class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        horizontalCuts.append(0)
        verticalCuts.append(0)
        horizontalCuts.append(h)
        verticalCuts.append(w)
        verticalCuts.sort()
        horizontalCuts.sort()
        wi,hi = 0,0
        for i in range(1,len(horizontalCuts)):
            hi = max(hi,abs(horizontalCuts[i])-horizontalCuts[i-1])
        
        for i in range(1,len(verticalCuts)):
            wi = max(wi,abs(verticalCuts[i])-verticalCuts[i-1])
            
        return (wi*hi)%((10**9)+7)
