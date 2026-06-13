class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        mapper = [chr(i) for i in range(122,96,-1)]
        
        res = ''
        i = 0
        for word in words:
            sum = 0
            for char in word:
                sum += weights[ord(char)%97]
            
            char = mapper[(sum%26)]
            res += char
        return res


