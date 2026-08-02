from functools import cache
class Solution:

    def predictTheWinner(self, nums: List[int]) -> bool:
        i = 0
        j = len(nums)-1
        @cache
        def solve(i,j):
            if i == j:
                return nums[i]
            choice_a = nums[i]  - solve(i+1,j)
            choice_b = nums[j] - solve(i,j-1)
            return max(choice_a,choice_b)
        score_d = solve(i,j)
        return score_d >= 0
        
        