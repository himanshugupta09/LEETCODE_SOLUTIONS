class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        def FindVal(l: int, r: int, P: str):
            if l == n:
                if r == n:
                    vals.append(P)
                else:
                    FindVal(l, r + 1, P + ')')
            elif l == r:
                FindVal(l + 1, r, P + '(')
            else:
                FindVal(l + 1, r, P + '(')
                FindVal(l, r + 1, P + ')')
        vals = []
        FindVal(0,0,"")
        return vals