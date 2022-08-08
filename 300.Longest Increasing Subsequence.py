class Solution:
    
    """
    This Approach includes the Prior Knowledge of the binary search ,lower_bound in 
    binary_search and higher_bound in Binary_search
    
    """
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = 1
        temp = [] # intsialize a temp array that wil contain our increasing subsequnce from
        temp.append(nums[0]) # the given sequnce
        
        # Now Start To loop over the given sequnce 
        for i in range(1,len(nums)):
            # if the last of temp is less than our nums current the we add it to last of temp               array
            if nums[i]>temp[-1]:
                temp.append(nums[i])
                n += 1
            else:
                """
                if not then we will add this element by firstly finding then correct place in 
                our new modified sequnce 
                Here we will use the bisec.bisect_left() function from the bisect module 
                which takes the array,element_to_insert,lower_bound_array,high_bound_array
                and finds the prefrable location for this elemnt and then we write this elemnt
                to that position
                
                keep in mind not to increase the valueof n as it only overwrites not adds to 
                the sequence
                """
                idx = bisect.bisect_left(temp,nums[i],0,len(temp))
                temp[idx] = nums[i]
                
        # At Final we return the value of n which is our required result
        
        return  n        
        
