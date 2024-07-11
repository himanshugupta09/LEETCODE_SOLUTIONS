class Solution:
    def reverseParentheses(self, s: str) -> str:
        stk = []
        ls = [0]*len(s)
        n = len(s)
        for i in range(n):
            if s[i] == '(':
                stk.append(i)
            elif s[i] == ')':
                j = stk[-1]
                stk.pop()
                ls[i] = j
                ls[j] = i
        res = []
        
        curr = 0
        dr = 1
        while curr  < n:
            if s[curr] == '(' or s[curr] == ')':
                curr  = ls[curr]
                dr = -dr
            else:
                res.append(s[curr])
            curr += dr
        return "".join(res)
                
                
            
                
