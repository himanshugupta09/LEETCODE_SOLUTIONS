class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        element = 0

        for num in nums:
            if count == 0:
                element = num
                count = 1
            elif element == num:
                count += 1
            else:
                count -= 1

        return element
