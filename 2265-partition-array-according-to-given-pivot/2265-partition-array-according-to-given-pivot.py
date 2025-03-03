class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        left = []
        right = []
        pvc = 0
        for i in nums:
            if i > pivot:
                right.append(i)
            elif i < pivot:
                left.append(i)
            else:
                pvc+=1
        nums = left + [pivot]*pvc + right
        return nums
        