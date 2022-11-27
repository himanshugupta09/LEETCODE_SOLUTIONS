class Solution:
    def earliestFullBloom(self, plantTime: List[int], growTime: List[int]) -> int:
        
        ''' 
        1.Create a list with elements as [plantTime[i],growTime[i]]
        
        2.now sort the obtained list on the Basis of thier growTime as key
        
        3. Declare Two Variables current and res for answer at last
        
        4. res will ontain our final answer , Now start itersting over the elements of the new list
        
        5. add the plantTime to cur res will contain the max of current and max
        
        '''
        
        series = list(zip(plantTime,growTime))
        
        series.sort(key = lambda x: -x[1])
        
        res = 0
        
        cur = 0
        
        for i,j in series:
            cur += i
            res = max(res,cur+j)
            
        return res
    
'''

Time Complexity : O(Log n)
Space Complexity : O(n)

'''    
        
        
        
        
