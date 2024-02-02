class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        res = []
        
        for i in range(1,10):
            num = i
            next_d = i+1
            
            while num <= high and next_d <= 9:
                num = num*10 + next_d
                if low <= num <= high:
                    res.append(num)
                next_d += 1
        res.sort()
        return res
        
            
