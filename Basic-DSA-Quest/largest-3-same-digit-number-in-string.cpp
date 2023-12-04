class Solution:
    def largestGoodInteger(self, num: str) -> str:
        
        res = ""
        n = -float('inf')
        
        for i in range(0,len(num)-2):
            if num[i] == num[i+1] and num[i+1] == num[i+2]:
                t = int(num[i:i+3])
                if t > n:
                    n = t
                    res = num[i:i+3]
        return res if res != 0 else ""
        
