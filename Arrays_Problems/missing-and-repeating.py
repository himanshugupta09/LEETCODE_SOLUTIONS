#User function Template for python3

class Solution:
    def findTwoElement( self,arr):
        n = len(arr)
        repeating = -1
        missing = -1
        
        # First pass: Mark visited elements
        for i in range(n):
            index = abs(arr[i]) - 1  # Get the index from the absolute value
            if arr[index] < 0:
                repeating = abs(arr[i])  # Found a repeating element
            else:
                arr[index] = -arr[index]  # Mark as visited
        
        # Second pass: Find the missing element
        for i in range(n):
            if arr[i] > 0:
                missing = i + 1  # Missing element is index + 1
        
        return repeating, missing


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findTwoElement(arr)
        print(str(ans[0]) + " " + str(ans[1]))
        tc = tc - 1

# } Driver Code Ends
