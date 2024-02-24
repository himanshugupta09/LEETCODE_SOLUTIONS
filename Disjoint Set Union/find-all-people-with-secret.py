class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        # Sort meetings in increasing order of time
        meetings.sort(key=lambda x: x[2])

        # Group Meetings in increasing order of time
        same_time_meetings = defaultdict(list)
        for x, y, t in meetings:
            same_time_meetings[t].append((x, y))
    
        # Create graph
        graph = UnionFind(n)
        graph.unite(firstPerson, 0)

        # Process in increasing order of time
        for t in same_time_meetings:
            # Unite two persons taking part in a meeting
            for x, y in same_time_meetings[t]:
                graph.unite(x, y)
            
            # If any one knows the secret, both will be connected to 0.
            # If no one knows the secret, then reset.
            for x, y in same_time_meetings[t]:
                if not graph.connected(x, 0):
                    # No need to check for y since x and y were united
                    graph.reset(x)
                    graph.reset(y)
        
        # Al those who are connected to 0 will know the secret
        return [i for i in range(n) if graph.connected(i, 0)]

class UnionFind:
    def __init__(self, nodes: int):
        # Initialize parent and rank arrays
        self.parent = [i for i in range(nodes)]
        self.rank = [0] * nodes

    def find(self, x: int) -> int:
        # Find the parent of node x. Use Path Compression
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def unite(self, x: int, y: int) -> None:
        # Unite two nodes x and y, if they are not already united
        px = self.find(x)
        py = self.find(y)
        if px != py:
            # Union by Rank Heuristic
            if self.rank[px] > self.rank[py]:
                self.parent[py] = px
            elif self.rank[px] < self.rank[py]:
                self.parent[px] = py
            else:
                self.parent[py] = px
                self.rank[px] += 1
    
    def connected(self, x: int, y: int) -> bool:
        # Check if two nodes x and y are connected or not
        return self.find(x) == self.find(y)
    
    def reset(self, x: int) -> None:
        # Reset the initial properties of node x
        self.parent[x] = x
        self.rank[x] = 0
