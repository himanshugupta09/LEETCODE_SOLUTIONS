class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height)-1
        max_area = -float('inf')
        while left <= right:
            area = (right-left)*(min(height[left],height[right]))
            if area > max_area:
                max_area = area
            if height[left] < height[right]:
                left += 1
            elif height[left] > height[right]:
                right -= 1
            else:
                left += 1
                right -= 1
        return max_area
        