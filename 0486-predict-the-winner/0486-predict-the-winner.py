class Solution:
    def solve(self,nums,i,j):
        if i == j:
            return nums[i]
        choice_a = nums[i]  - self.solve(nums,i+1,j)
        choice_b = nums[j] - self.solve(nums,i,j-1)
        return max(choice_a,choice_b)

    def predictTheWinner(self, nums: List[int]) -> bool:
        i = 0
        j = len(nums)-1
        
        score_d = self.solve(nums,i,j)
        return score_d >= 0
        
        