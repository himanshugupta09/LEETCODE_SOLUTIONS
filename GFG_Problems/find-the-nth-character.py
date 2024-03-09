#User function Template for python3

class Solution:
    def nthCharacter(self, s, r, n):
        # code here
        
        
        while r:
            t = ''
            for j in range((n//2)+1):
                if s[j] == '1':
                    t += '10'
                else:
                    t += '01'
            s = t
            r -= 1
        return s[n]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        snr = input().split()
        S, R, N = snr[0], int(snr[1]), int(snr[2])
        ob = Solution()
        print(ob.nthCharacter(S, R, N))
# } Driver Code Ends
