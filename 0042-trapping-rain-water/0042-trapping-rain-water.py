class Solution:
    def trap(self, height: List[int]) -> int:
        stack = []
        max_water = 0
        for i in range(len(height)):
            while stack and height[i] > height[stack[-1]]:
                mid = stack.pop()
                if not stack:
                    break
                left = stack[-1]
                right = i
                width = right-left-1
                bd = min(height[left],height[right])-height[mid]
                max_water += width*bd
            stack.append(i)
        return max_water