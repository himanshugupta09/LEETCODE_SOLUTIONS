class Solution:
    """
    This is a  helper function named match will look  for the pattern in list of words by           picking a word and mking a map for it and then comparing keys of word from words and the         pattern
    
    This is approach requires two hash maps for the implementaion
    """
    
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        
         # Checks if a word matches the pattern
            def checker(word,pattern):
                h1 = {} # first map
                h2 = {} # second map
                # fill the hashmaps by taking each words from word and pattern
                for i in range(len(word)):
                    w = word[i]
                    p = pattern[i]
                    
                    if w not in h1:
                        h1[w] = p
                    if p not in h2:
                        h2[p] = w
                    if h1[w] != p or h2[p] != w:
                        return False
                return True
            res = [] #resultant Array
            for word in words:
                if checker(word,pattern):
                    res.append(word)
            return res        
        
