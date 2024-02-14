class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos = [i for i in nums if i > 0]
        neg = [i for i in nums if i < 0]
        
        res = []
       
        
        for k in range(len(nums)):
            if k%2 == 0:
                res.append(pos[0])
                pos.pop(0)
            else:
                res.append(neg[0])
                neg.pop(0)
        del pos
        del neg
        return res
