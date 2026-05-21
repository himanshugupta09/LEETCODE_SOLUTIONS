class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        res = []
        for i in range(1,len(nums),2):
            temp = [nums[i]]*nums[i-1]
            res.extend(temp)
        return res
        