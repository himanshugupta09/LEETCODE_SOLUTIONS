class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        stack = []
        max_area = -1
        n = len(heights)
        for i in range(n):
            while stack  and heights[stack[-1]] > heights[i]:
                height = heights[stack.pop()]
                left = stack[-1] if stack else -1
                width = i-left-1
                max_area = max(max_area,height*width)
            stack.append(i)
        while stack:
            h = heights[stack.pop()]
            left = stack[-1] if stack else -1
            width = n - left - 1

            max_area = max(max_area, h * width)

        return max_area
        
                

        