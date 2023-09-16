class Solution:
    def minLengthAfterRemovals(self, nums: List[int]) -> int:
        dtb = {}
        for i in nums:
            if i in dtb:
                dtb[i] += 1
            else:
                dtb[i] = 1
        most_wanted = max(dtb.values())
        #print(most_wanted)
        if most_wanted > (len(nums)/2):
            return 2*most_wanted - len(nums)
        if len(nums)%2 != 0:
            return 1
        else:
            return 0
            
            
            
                
            
            
