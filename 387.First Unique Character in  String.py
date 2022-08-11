"""
In this Approach we had used a hash map will store the indexes of the occuances of the string characters 

"""

class Solution:
    def firstUniqChar(self, s: str) -> int:
        m = {}

# We will now fill the hashmap by iterating over the string 
# with string characters as the key and their index of occurance as the value 
# here we had used map as char:list where our list will contains the index of the occurance of that character in ouor given string
        for i in range(len(s)):
            if s[i] in m:
                m[s[i]].append(i)
            else:
                m[s[i]] = [i]
             
        # Now we will Iterate over the hashmap and look for the key that has only single value
        for i in m:
            if len(m[i]) == 1:
                
                # here we had unpacked the list 
                a = (lambda x: x)(*m[i])
                return a
        return -1    
            
         
        
