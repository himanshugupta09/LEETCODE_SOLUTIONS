from collections import defaultdict,deque
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        q = deque()
        adj = defaultdict(list)
        indeg = [0]*numCourses

        for u,v in prerequisites:
            adj[v].append(u)
            indeg[u] += 1
        
        for i in range(numCourses):
            if indeg[i] == 0:
                q.append(i)
        
        order = []
        exp = 0
        while q:
            fr = q.popleft()
            exp += 1
            order.append(fr)
            for neigh in adj[fr]:
                indeg[neigh] -= 1
                if indeg[neigh] == 0:
                    q.append(neigh)
        return order if exp == numCourses else []