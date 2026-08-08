class Solution:
    def validSequence(self, word1: str, word2: str) -> List[int]:
        back_match = [-1]*len(word2)
        i = len(word1)-1
        j = len(word2)-1
        while i >=0 and j >= 0:
            if word1[i] == word2[j]:
                back_match[j] = i
                i -= 1
                j -=1
            else:
                i -= 1
        
        skip = False
        res = []
        i  = 0
        j = 0
        while i < len(word1) and j < len(word2): 
            if word1[i] == word2[j]:
                res.append(i)
                i += 1
                j += 1
            else:
                if not skip:
                    # Scenario A: It's the last char of word2, so an edit is always safe.
                    # Scenario B: It's not the last char, BUT the oracle says the rest fits.
                    if (j + 1 == len(word2)) or (j + 1 < len(word2) and back_match[j+1] > i):
                        skip = True
                        res.append(i)
                        i += 1
                        j += 1
                    else:
                        # Can't edit, just move word1 pointer
                        i += 1
                else:
                    # We already used our edit, just move word1 pointer
                    i += 1

        return res if len(res) == len(word2) else []