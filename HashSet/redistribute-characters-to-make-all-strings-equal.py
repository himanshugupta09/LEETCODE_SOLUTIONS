class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        mp = {}
        n = len(words)
        for word in words:
            for char in word:
                if char in mp:
                    mp[char] += 1
                else:
                    mp[char] = 1
        for i in mp.values():
            if i%n != 0:
                return False
        return True
        
