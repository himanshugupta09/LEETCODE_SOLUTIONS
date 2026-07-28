class Solution():
    def longestString(self, words):
        # code here
        if not words:
            return ""
        words.sort()
        hashed = set()
        longestPrefix = ""
        for word in words:
            if len(word) == 1 or word[:-1] in hashed:
                hashed.add(word)
                
                if len(word) > len(longestPrefix):
                    longestPrefix = word
        return longestPrefix