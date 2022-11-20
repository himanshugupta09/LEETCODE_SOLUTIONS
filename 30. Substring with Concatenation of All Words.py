"""
    APPROACH 1 --------> USING HASHMAP
"""    


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n = len(s)
        k = len(words)
        word_len = len(words[0])
        substring_size = word_len*k
        word_count = collections.Counter(words)
        
        def check(i):
            rem = word_count.copy()
            words_used = 0
            
            # Each iteration will check for a match in words
            
            for j in range(i,i+substring_size,word_len):
                sub = s[j:j+word_len]
                if rem[sub]>0:
                    rem[sub]-=1
                    words_used += 1
                else:
                    break
                    
            return words_used == k
        
        ans = []
        for i in range(n-substring_size+1):
            if check(i):
                ans.append(i)
        
        return ans
      
"""
======================================================================================================================================================================
                                         APPROACH 2 -------> USING THE SLIDING WINDOW TECHNIQUE
======================================================================================================================================================================
"""

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        
        """
        In this approach we have modified the previous approach and used Sliding Window 
        Technique 
        """
        n = len(s)
        k = len(words)
        
        word_len = len(words[0])
        substring_Size = word_len*k
        word_count = collections.Counter(words)
        
        def slidingWindow(left):
            word_found = collections.defaultdict(int)
            words_used = 0
            excess_word = False
            
            for right in range(left,n,word_len):
                
                if right + word_len > n:
                    break
                
                sub = s[right:right+word_len]
                
                if sub not in word_count:
                    word_found = collections.defaultdict(int)
                    words_used = 0
                    excess_word = False
                    left = right+word_len
                else:
                    
                    while right - left == substring_size or excess_word:
                        l = s[left:left+word_len]
                        left += word_len
                        word_found[l] -= 1
                        
                        if word_found[l] == word_count[l]:
                            excess_word = False
                            
                        else:
                            words_used -= 1
                    word_found[sub] += 1
                    if word_found[sub] <= word_count[sub]:
                        words_used += 1
                    else:
                        excess_word = True
                        
                        
                    if words_used == k and not excess_word:
                        ans.append(left)
            
            ans = []
            for i in range(word_len):
                slidingWindow(i)
                
            return ans    
"""

Time Complexity: O(N)
Space Complexity:O(N)
"""

             





          
