class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        from collections import Counter
        ct1 = Counter(arr)
        ct2 = Counter(target)
        if ct1 != ct2:
            return False
        else:
            return True
