class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        def splitter(num):
            string = []
            while num != 0:
                string.append((num%10))
                num //= 10
            return string[::-1] 
        result = []
        for num in nums:
            splits = splitter(num)
            result.extend(splits)
        return result