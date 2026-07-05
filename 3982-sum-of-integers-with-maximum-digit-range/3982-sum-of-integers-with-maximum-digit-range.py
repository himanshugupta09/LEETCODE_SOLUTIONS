class Solution:
    def maxDigitRange(self, nums: list[int]) -> int:
        maxD = 0
        if len(nums) == 1:
            return nums[0]
        for  num in nums:
            strr = str(num)
            lar = 0
            sm = 9
            for i in strr:
                lar = max(lar,int(i))
                sm = min(sm,int(i))
            maxD = max(maxD,lar-sm)
        res = 0
        for  num in nums:
            mld = 0
            strr = str(num)
            lar = 0
            sm = 9
            for i in strr:
                lar = max(lar,int(i))
                sm = min(sm,int(i))
            mld = max(mld,lar-sm)
            if mld == maxD:
                res += num
        return res
        