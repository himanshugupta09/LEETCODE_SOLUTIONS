class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        mod = 10**9 + 7
        n = len(arr)
        arr.sort()
        dp = [1]*n  # intialize the  dp array with 1's so that it stores all possible nodes that
                    # a tree a can have 
        
        # Create a Hash map with all array elements as value and their index as key
        index = {x:i for i,x in enumerate(arr)} 
        
        
        for i,y  in enumerate(arr):
            for j in range(i):
                if y % arr[j] == 0:
                    right = y//arr[j]
                    
                    if right in index:
                        dp[i] = (dp[i] + dp[j]*dp[index[right]])%mod
                        
        
        return sum(dp)%mod
        
        """
        Time Complexity : O(n^2)
        Space Complexity : O(n)
        
        """
