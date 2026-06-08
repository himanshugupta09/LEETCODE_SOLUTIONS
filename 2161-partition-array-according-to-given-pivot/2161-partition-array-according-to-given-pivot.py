class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        return (
            [x for x in nums if x < pivot] +
            [x for x in nums if x == pivot] +
            [x for x in nums if x > pivot]
        )