class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        """
        In this problem we are gonna to use two hash maps ,
        the first hash map will store the Frequncy count of the numbers 
        
        Second hash map will be Hypothetical map which will tries to record the numbers which 
        can be hypothetically added to existing subSequence
        
        """
        
        # Frequncy count map
        fm = collections.Counter(nums)
        end = defaultdict(int)
        
        for i in nums:
            if fm[i]:
                fm[i] -= 1
                
                if end[i-1]:
                    end[i] += 1
                    end[i-1] -= 1
                
                elif fm[i+1] and fm[i+2]:
                    fm[i+1] -= 1
                    fm[i+2] -= 1
                    end[i+2] += 1
                else:
                    return False
        return True       
                    
                    
                    
                    
