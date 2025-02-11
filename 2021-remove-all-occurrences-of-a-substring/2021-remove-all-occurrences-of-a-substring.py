class Solution:
    def checkmatch(self,stack,part):
        return "".join(stack[-len(part):]) == part
        
    def removeOccurrences(self, s: str, part: str) -> str:
        stack  = []
        n = len(s)
        m = len(part)
        for i in range(n):
            stack.append(s[i])
            if len(stack) >= len(part) and self.checkmatch(stack,part):
                for i in range(len(part)):
                    stack.pop()

               
        return "".join(stack)
                

        