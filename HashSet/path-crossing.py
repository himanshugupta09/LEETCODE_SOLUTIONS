class Solution:
    def isPathCrossing(self, path: str) -> bool:
        vis = set()
        x = 0
        y = 0
        vis.add((x,y))
        for i in path:
            if i == 'N':
                y += 1
            elif i == 'S':
                y -= 1
            elif i == 'E':
                x += 1
            else:
                x -= 1
            if (x,y) in vis:
                return True
            else:
                vis.add((x,y))
        return False
        
