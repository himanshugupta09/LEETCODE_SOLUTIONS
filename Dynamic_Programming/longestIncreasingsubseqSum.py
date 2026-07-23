class Solution:
	def maxSumIS(self, arr):
	    n = len(arr)
		# code here
		dp = [i for i in arr]
		for i in range(1,n):
		    for j in range(i):
		        if arr[i] >  arr[j]:
		            dp[i] = max(dp[i],dp[j]+arr[i])
		return max(dp)