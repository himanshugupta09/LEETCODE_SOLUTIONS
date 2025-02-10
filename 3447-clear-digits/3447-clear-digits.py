class Solution:
    def clearDigits(self, s: str) -> str:
        stk = []
        for i in s:
            if i.isalpha():
                stk.append(i)
            else:
                stk.pop()
        return "".join(stk)
        