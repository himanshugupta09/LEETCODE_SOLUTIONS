class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split(" ")
        
        res = len(words)
        for word in words:
            for j in range(len(word)):
                if word[j] in brokenLetters:
                    res -= 1
                    break
        return res
        