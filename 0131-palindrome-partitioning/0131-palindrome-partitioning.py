class Solution:
    def solve(self,idx,path,s):
        if idx == len(s):
            self.res.append(path[:])
            return
        for end in range(idx,len(s)):
            if s[idx:end+1] == s[idx:end+1][::-1]:
                path.append(s[idx:end+1])
                self.solve(end+1,path,s)
                path.pop()
        
    def partition(self, s: str) -> List[List[str]]:
        self.res = []
        self.solve(0,[],s)
        return self.res