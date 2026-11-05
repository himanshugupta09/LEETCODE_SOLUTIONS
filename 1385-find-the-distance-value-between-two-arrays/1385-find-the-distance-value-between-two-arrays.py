class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        arr2.sort()
        res = 0
        def find_nearest(arr, target):
            idx = bisect.bisect_left(arr, target)
            
            if idx == 0:
                return arr[0]
            if idx == len(arr):
                return arr[-1]
            before = arr[idx - 1]
            after = arr[idx]
            
            if abs(after - target) <= abs(before - target):
                return after
            else:
                return before
        for num in arr1:
            element = find_nearest(arr2,num)
            if abs(num-element) > d:
                res += 1
        return res


        