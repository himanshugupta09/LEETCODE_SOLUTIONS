class UnionFind:
    def __init__(self,n:int):
        self.n = n
        self.parent = [i for i in range(n)]
        self.compS = [1 for i in range(n)]
    def get_parent(self,x:int)->int:
        if self.parent[x] == x:
            return x
        self.parent[x] = self.get_parent(self.parent[x])
        return self.parent[x]
    
    def union_set(self,x:int,y:int):
        parx, pary = self.get_parent(x), self.get_parent(y)
        if parx != pary:
            if self.compS[parx] < self.compS[pary]:
                parx, pary = pary, parx
            self.parent[pary] = parx
            self.compS[parx] += self.compS[pary]
    def add_edge(self,x:int,y:int):
        self.union_set(x,y)
    def is_connected(self)->bool:
        return self.compS[self.get_parent(0)] == self.n
    
        
class Solution:
    def getPrimeFactors(self, x: int) -> int:
        for i in range(2, int(sqrt(x)) + 1):
            if x % i == 0:
                while x % i == 0:
                    x //= i
                yield i
        if x != 1:
            yield x
    
    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        n = len(nums)
        if n == 1:
            return True
        g = UnionFind(n)
        seen = {}
        for i in range(n):
            if nums[i] == 1:
                return False
            for prime in self.getPrimeFactors(nums[i]):
                if prime in seen:
                    g.add_edge(i, seen[prime])
                else:
                    seen[prime] = i
        return g.is_connected()
        
