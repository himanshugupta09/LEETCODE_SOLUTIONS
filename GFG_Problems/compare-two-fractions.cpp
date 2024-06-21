#User function Template for python3


class Solution:
    def compareFrac (self, str):
        a,b=str.strip().split()
        a=a.strip(',')
        
        # getting numerator and denominator from fractions
        v1,v2=map(int,a.split('/'))
        v3,v4=map(int,b.split('/'))
        
        # cross multiplication to decide which fraction is bigger
        if v1*v4==v2*v3:
            return "equal"
        elif v1*v4>v2*v3:
            return a
        else:
            return b
        # code here
        



#{ 
 # Driver Code Starts
#Initial Template for Python 3
import re

if __name__ == '__main__':
    ob = Solution()
    t = int(input())
    for _ in range(t):
        str = input()
        print(ob.compareFrac(str))

# } Driver Code Ends
