class Solution:
    def solve(self,s,i,res,path):
        if i == len(s):
            res.append(path)
            return
        path += s[i]
        self.solve(s,i+1,res,path)
        path = path[:-1]
        self.solve(s,i+1,res,path)
        return
    def powerSet(self, s):
        # Code here
        res = []
        temp = ''
        self.solve(s,0,res,temp)
        res.sort()
        return res
Solution().powerSet("abc")
		