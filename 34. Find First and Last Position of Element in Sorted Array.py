# Simple Approach __________________________________________________________________________________________________________________________________________________
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return [-1,-1]
        if len(nums) == 1 and target in nums:
            return [0,0]
        
        has = defaultdict(list)
        for i in range(len(nums)):
            if nums[i] in has:
                has[nums[i]].append(i)
            else:
                has[nums[i]] = [i]
        if target in nums:
            if len(has[target]) == 1:
                return has[target]*2
            elif len(has[target])>2:
                a = has[target]
                b = list()
                b.append(a[0])
                b.append(a[-1])
                return b
            return has[target]
                
        else:
            return [-1,-1]

          
#________________________________________________________________________________________________________________________________________________________________________          
#______________________________________________________________________ APPROACH WITH BINARY  SEARCH_____________________________________________________________________
#________________________________________________________________________________________________________________________________________________________________________


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
                
        
