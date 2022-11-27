class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix)
        m = len(matrix[0])
        low = 0
        high = n-1
        while (high>=0 and low<m):
            if matrix[high][low] == target:
                return True
            elif matrix[high][low]<target:
                low+=1
            else:
                high-=1
        return False         
      
      
# https://leetcode.com/problems/search-a-2d-matrix-ii/      
                
