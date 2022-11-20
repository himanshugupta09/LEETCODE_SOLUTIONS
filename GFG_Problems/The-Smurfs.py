#User function Template for python3

class Solution:
    def minFind(self, n, a):
        # code here
        r = a.count("R")
        g = a.count("G")
        b = a.count("B")
        
        if r == n or b == n or g == n:
            return n
        elif r%2 == 0 and g%2 == 0 and b%2 == 0:
            return 2
        elif r%2 != 0 and g%2 != 0 and b%2 != 0:
            return 2
        else:
            return 1
            


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = input().split()
        
        ob = Solution()
        print(ob.minFind(n, a))
# } Driver Code Ends
