class Solution:
    def getDigitSum(self,num:int)->int:
        res = 0
        while num > 0:
            res +=  num%10
            num //= 10
        return res

    def minElement(self, nums: List[int]) -> int:
        minEle = 100000
        for num in nums:
            digit_sum = self.getDigitSum(num)
            minEle = min(minEle,digit_sum)
        return minEle
        