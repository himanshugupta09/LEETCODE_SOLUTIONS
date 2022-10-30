#User function Template for python3

class Solution:
	def NoOfChicks(self, N):
		# Code here
		dp = [0]*(N+1)
		
		dp[0] = 0
		dp[1] = 1
		
		ans = 1
		
		for i in range(2,N+1):
		    if i>6:
		        ans -= dp[i-6]
		    dp[i] = ans*2
		    ans += dp[i]
		return ans    
		        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		N = int(input())
		obj = Solution()
		ans = obj.NoOfChicks(N)
		print(ans)

# } Driver Code Ends
