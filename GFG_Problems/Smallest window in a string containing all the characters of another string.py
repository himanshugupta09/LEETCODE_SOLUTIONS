#User function Template for python3


class Solution:
    
    #Function to find the smallest window in the string s consisting
    #of all the characters of string p.
    def smallestWindow(self, s, p):
        #code here
        
        
        # NULL case if any of string is of size 0
        if not p or not s:
            return -1
            
        # This hashmap will contain all the counts of the characters of string p
        
        map_p = {}
        for i in p:
            if i not in map_p:
                map_p[i] = 1
            else:
                map_p[i] += 1
        
        ms = len(map_p)
        
        # Filter all the characters from s into liist with index for refrences ease to p
        
        ls = []
        
        for idx,char in enumerate(s):
            if char in map_p:
                ls.append((idx,char))
                
        # Now set to point to string s starting from index 0
        i,j = 0,0
        
        # now look at only characters present in ls list as ti will save time 
        
        form = 0 # refrence to get how many possiible answers we have found
        
        
        # Dictionary which keeps a count of all the unique characters in the current window.
        window_cnt = {}  # This will contain all possible string along with thier size 
        
        #result as of form (length,start_idx,end_idx) in reference to fetch required ans from s string
        
        res = float("inf"),None,None
        
        while j<len(s):
            b = s[j]
            window_cnt[b] = window_cnt.get(b,0) + 1
            
        # If the frequency of the current character added equals to the desired count in t then increment the formed count by 1.
            if b in map_p and window_cnt[b] == map_p[b]:
                form += 1
                
            # Try and contract the window till the point where it ceases to be 'desirable'.
            while i <= j and form == ms:
                b = s[i]
                    
                if j-i+1 < res[0]:
                    res = (j-i+1,i,j)
                        
             # The character at the position pointed by the `left` pointer is no longer a part of the window.
                window_cnt[b] -= 1
                if b in map_p and window_cnt[b] < map_p[b]:
                    form -= 1
                     # Move the left pointer ahead, this would help to look for a new window.
                i += 1
                    # Keep expanding the window once we are done contracting.
            j += 1
            
        if res[0] == float("inf"):
            return -1
        else:
            return s[res[1]:res[2] +1]    
                        
                 
         
        
        
        
                    
                
                


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        s=str(input())
        p=str(input())
        ob = Solution()
        print(ob.smallestWindow(s,p))
# } Driver Code Ends
