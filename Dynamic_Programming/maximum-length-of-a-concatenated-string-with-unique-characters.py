class Solution:
    def maxLength(self, arr: List[str]) -> int:
        def is_unique(s):
            return len(s) == len(set(s))
        def solve(idx,curr_str):
            nonlocal max_len
            
            max_len = max(max_len,len(curr_str))
            
            for i in range(idx,len(arr)):
                if is_unique(curr_str+arr[i]):
                    solve(i+1,curr_str+arr[i])
        max_len = 0
        solve(0,"")
        return max_len
            
        
