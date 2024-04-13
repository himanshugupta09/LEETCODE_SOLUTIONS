#User function Template for python3

class Solution:
    def reversedBits(self, x):
        # code here 
        bins = bin(x)
        bins = list(bins)
        bins.remove('b')
        
        bins = bins[::-1]
        st = ''.join(bins) +'0'*(32-len(bins))
        
        return int(st,2)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        X=int(input())
        
        ob = Solution()
        print(ob.reversedBits(X))
# } Driver Code Ends
