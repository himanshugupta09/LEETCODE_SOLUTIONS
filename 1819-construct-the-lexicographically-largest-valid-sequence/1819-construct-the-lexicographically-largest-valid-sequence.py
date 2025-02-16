class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        res = [0]*(2*n-1)
        isUsed = [False]*(n+1)
        self.solve(0,res,isUsed,n)
        return res
    def solve(self,idx,res,isUsed,tar):
        if idx == len(res):
            return True
        if res[idx] != 0:
            return self.solve(idx+1,res,isUsed,tar)
        for i in range(tar,0,-1):
            if isUsed[i] == True:
                continue
            isUsed[i] = True
            res[idx] = i
            if i == 1:
                if self.solve(idx+1,res,isUsed,tar):
                    return True
            elif idx+i< len(res) and res[idx+i] == 0:
                res[idx+i] = i
                if self.solve(idx+1,res,isUsed,tar):
                    return True
                res[idx+i] = 0
            res[idx] = 0
            isUsed[i] = False
        return False

        