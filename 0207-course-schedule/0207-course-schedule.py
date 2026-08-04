from collections import defaultdict,deque
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = defaultdict(list)
        indeg = [0]*numCourses
        for u,v in prerequisites:
            adj[v].append(u)
            indeg[u] += 1
        q = deque()
        for i in range(numCourses):
            if indeg[i] == 0:
                q.append(i)
        took = 0
        while q:
            took += 1
            fr = q.popleft()
            for neigh in adj[fr]:
                indeg[neigh] -= 1
                if indeg[neigh] == 0:
                    q.append(neigh)
        return numCourses == took
        

        
        