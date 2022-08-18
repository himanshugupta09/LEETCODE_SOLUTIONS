class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        
        #  firsly get the size of list
        n = len(arr)
        h = n//2
        
        # Counter will create  a hashmap that will contains the freq_count of each number 
        count = Counter(arr)
        
        # Now at this step we will sort key,val in descending order
        freq_count = sorted(count.values(),reverse = True)
        
        ans = 0
        
        while h > 0:
            h -= freq_count[ans]
            ans += 1
            
        return ans    
