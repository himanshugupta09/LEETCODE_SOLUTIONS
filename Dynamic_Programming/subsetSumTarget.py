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
class Solution:
    # def solve(self,arr,i,sum,memo):
    #     if sum == 0:
    #         return True
    #     if i == len(arr):
    #         return False
    #     if (i,sum) in memo:
    #         return memo[(i,sum)]
    #     not_take = self.solve(arr, i + 1,sum, memo)
        
    #     take = False
    #     if arr[i] <= sum:
    #         take = self.solve(arr, i + 1,sum - arr[i], memo)
    #     memo[(i,sum)] = take or not_take
    #     return memo[(i,sum)]
    def isSubsetSum (self, arr, sum):
        # code here 
        dp = [False]*(sum+1)
        dp[0] = True
        for num in arr:
            for curr_sum in range(sum,num-1,-1):
                if dp[curr_sum - num]:
                    dp[curr_sum] = True
        return dp[sum]
            
