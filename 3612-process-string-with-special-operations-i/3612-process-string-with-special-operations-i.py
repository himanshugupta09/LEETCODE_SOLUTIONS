class Solution:
    def processStr(self, s: str) -> str:
        res = []
        ops = set(['%','#','*'])
        for char in s:
            if char not in ops:
                res.append(char)
            else:
                if char == '%':
                    res = res[::-1]
                elif char == '#':
                    res += res
                elif char == '*' and len(res) > 0:
                    res.pop()
        return ''.join(res)