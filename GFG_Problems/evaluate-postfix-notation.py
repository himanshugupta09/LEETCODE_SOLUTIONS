#{ 
 # Driver Code Starts
#Initial Template for Python 3


# } Driver Code Ends

#import math
class Solution:
    def evaluate(self, arr):
        # code here
        stk = []
        op = {'+','-','*','/'}
        for i in arr:
            if i not in op:
                stk.append(int(i))
            else:
                b = stk.pop()
                a = stk.pop()
                c = -1
                if i == '+':
                    c = b+a
                elif i == '*':
                    c = a*b
                elif i  == '/':
                    c = int(a/b)
                else:
                    c = a-b
                stk.append(c)
        return stk[0]


#{ 
 # Driver Code Starts.

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = input().split()
        solution = Solution()
        print(solution.evaluate(arr))
        print("~")

# } Driver Code Ends
