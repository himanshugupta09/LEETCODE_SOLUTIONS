class Solution:
    
    def solve(self,tiles,string,vis,hashSet):
        hashSet.add(string)
        for pos,char in enumerate(tiles):
            if not vis[pos]:
                vis[pos] = True
                self.solve(tiles,string+char,vis,hashSet)
                vis[pos]= False
        
    def numTilePossibilities(self, tiles: str) -> int:
        n = len(tiles)
        if n ==  1:
            return 1
        vis = [False]*n
        hashSet = set()
        self.solve(tiles,"",vis,hashSet)
        return len(hashSet)-1
        