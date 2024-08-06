#User function Template for python3
class Solution:
    def isValid(self, str):
        #code here
        if str.count('.') != 3:
            return False
        ds = str.split('.')
        if len(ds) != 4:
            return False
        for i in ds:
            if not(i) or not(0 <= int(i) <= 255):
                return False
            if len(i) > 1 and i[0] == '0':
                return False
        return True
        



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        ob = Solution()
        if (ob.isValid(s)):
            print("true")
        else:
            print("false")

# } Driver Code Ends
