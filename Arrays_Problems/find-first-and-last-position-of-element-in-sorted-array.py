class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def getidx(nums,target,getFirst):
            s,e = 0,len(nums)-1
            ans = -1
            while s<=e:
                md = s + (e-s)//2
                if nums[md] == target:
                    ans = md
                    if getFirst:
                        e = md-1
                    else:
                        s = md+1
                elif nums[md]>target:
                    e = md-1
                else:
                    s = md+1
            return ans
        res = [-1]*2
        fs = getidx(nums,target,True)
        if(fs == -1):
            return res
        ls = getidx(nums,target,False)
        res[0] = fs
        res[1] = ls
        return res
                
        
