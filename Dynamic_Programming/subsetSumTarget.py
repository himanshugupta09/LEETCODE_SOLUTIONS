"""
Mahtmatical model to solve it 
class Solution:
    def solve(self,arr,i,sum):
        if sum == 0:
            return True
        if i == len(arr):
            return False
        take = self.solve(arr,i+1,sum-arr[i])
        not_take = self.solve(arr,i+1,sum)
        return take or not_take
    def isSubsetSum (self, arr, sum):
        # code here 
        return self.solve(arr,0,sum)
        
        
"""