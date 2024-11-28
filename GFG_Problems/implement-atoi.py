#User function template for Python
class Solution:
    def myAtoi(self, s):
        # Code here
        i = 0
        n = len(s)
        
        # 1. Skip leading whitespaces
        while i < n and s[i] == ' ':
            i += 1
        
        # 2. Handle optional sign
        if i < n and (s[i] == '+' or s[i] == '-'):
            sign = -1 if s[i] == '-' else 1
            i += 1
        else:
            sign = 1
        
        # 3. Convert digits to integer
        num = 0
        while i < n and s[i].isdigit():
            num = num * 10 + int(s[i])
            i += 1
        
        # 4. Apply sign
        num *= sign
        
        # 5. Clamp to 32-bit signed integer range
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        if num > INT_MAX:
            return INT_MAX
        elif num < INT_MIN:
            return INT_MIN
        return num



#{ 
 # Driver Code Starts
#Initial template for Python

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = input()
        ob = Solution()
        print(ob.myAtoi(s))
        print("~")

# } Driver Code Ends
