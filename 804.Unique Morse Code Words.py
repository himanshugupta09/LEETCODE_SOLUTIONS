class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        
        encode = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        
        Hash = {"".join(encode[ord(w) - ord('a')] for w in word) for word in words}
        
        return len(Hash)
