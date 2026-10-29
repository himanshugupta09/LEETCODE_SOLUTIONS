class Solution:
    def dailyTemperatures(self, temp: list[int]) -> list[int]:
        stk = []
        res = [0]*len(temp)

        for i in range(len(temp)):
            if not stk or temp[stk[-1]] > temp[i]:
                stk.append(i)
            else:
                while stk and temp[stk[-1]] < temp[i]:
                    res[stk[-1]] = i-stk[-1]
                    stk.pop()
                stk.append(i)
        return res


