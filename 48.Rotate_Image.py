class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        dic = {}
        a = 1
        for i in range(len(matrix)):
            dic[a] = []
            
            for j in range(len(matrix)):
                dic[a].append(matrix[j][i])
                
            dic[a] = dic[a][::-1]    
            a += 1    
        #print(dic)      
        a = 1
        for i in range(len(matrix)):
            matrix[i] = dic[a]
            a += 1
            
        return (matrix)   
                
                
        
        
