class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
"""
One of the solution to given problem can be creating another 2D matirx and then place elements traversing in particular row or columns but as per the requirements we  do nt have to create any n^2 extra space as well this approach can also tends to TLE.



Another a better approach can be using a hash_map or dictionary in terms of python which will have keys as number of rows and list as values



"""        
        
# here a empty dictionary is declared
        dic = {}
# then we declared a variable which will works as keys in dictionary     
        a = 1
    
# Now we iterate by keeping i fixed for col and changing j for rows     
        for i in range(len(matrix)):
        
        # here we have assigned a empty list as value to key a in dictionary
            dic[a] = []
        
        # This loop will change row keeping column fix
            for j in range(len(matrix)):
                
        # Now append all responding values of jth column to ath key in dictionary        
                dic[a].append(matrix[j][i])
            
            # Since we have to rotate about 90 deg so we assigned reverse of the list to its respoding             # key in dictionary    
            dic[a] = dic[a][::-1]    
            a += 1    
        #print(dic)      
        a = 1
        # Now simply replace old row of the matrix with dictionary corresponding key for the row no.
        for i in range(len(matrix)):
            matrix[i] = dic[a]
            a += 1
            
        return (matrix)   
"""

Time Complexity: O(n^2)
Space Complexity: O(n)

Please upvote if you liked 

"""                
                
        
        
