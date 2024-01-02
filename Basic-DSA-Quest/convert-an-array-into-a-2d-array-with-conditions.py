class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        pres = [0]*len(nums)
        
        
        n = len(nums)
        res = []
        
        while pres.count(0)  != 0:
            i = 0
            temp = []
            
            while i < n:
                if nums[i] not in temp and pres[i] == 0:
                    temp.append(nums[i])
                    pres[i] = 1
                i += 1
            res.append(temp)
        return res
