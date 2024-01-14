class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False
        else:
            mp1 = {}
            mp2 = {}
            for i in word1:
                if i in mp1:
                    mp1[i] += 1
                else:
                    mp1[i] = 1
            for i in word2:
                if i in mp2:
                    mp2[i] += 1
                else:
                    mp2[i] = 1
            ls1 = list(mp1.values())
            ls1.sort()
            ls2 = list(mp2.values())
            ls2.sort()
            
            
            return ls1 == ls2 and (mp1.keys() == mp2.keys())
            
