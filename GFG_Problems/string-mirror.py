class Solution:
    def stringMirror(self, str : str) -> str:
        # code here
        res = ""
        res += str[0]
        for i in  range(1,len(str)):
            if ord(str[i]) <= ord(str[i-1]) and ord(str[i]) < ord(str[0]):
                res += str[i]
            else:
                break
        rev = res[::-1]
        res += rev
        return res
        



#{ 
 # Driver Code Starts
if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        str = (input())
        
        obj = Solution()
        res = obj.stringMirror(str)
        
        print(res)
        

# } Driver Code Ends
