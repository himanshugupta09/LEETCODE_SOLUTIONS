class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        sen = sentence.split()
        for i,word in enumerate(sen,1):
            if word[:len(searchWord)] == searchWord:
                return i
        return -1
