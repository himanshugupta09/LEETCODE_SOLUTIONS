class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        hashset = set()
        for num in arr1:
            
            for i in range(len(str(num))):
                hashset.add(str(num)[:i+1])
        res = 0
        for num in arr2:
            for i in range(len(str(num))):
                if str(num)[:i+1] in hashset:
                    res = max(res,len(str(num)[:i])+1)
        return res

        