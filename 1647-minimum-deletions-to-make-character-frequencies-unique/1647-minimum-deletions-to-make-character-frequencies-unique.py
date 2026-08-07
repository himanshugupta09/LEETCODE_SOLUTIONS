class Solution:
    def minDeletions(self, s: str) -> int:
        freq = set()
        ls = [i for i in s]
        ls.sort()
        last = ls[0]
        cnt = 1
        dels = 0
        
        ls.append('$')
        for i in range(1,len(ls)):
            if ls[i] != last:
                if cnt not in freq:
                    freq.add(cnt)
                    cnt = 1
                    last  = ls[i]
                else:
                    while cnt > 0  and cnt in freq:
                        cnt -= 1
                        dels += 1
                    if cnt == 0:
                        cnt = 1
                        last = ls[i]
                    else:
                        freq.add(cnt)
                        cnt = 1
                        last = ls[i]
            else:
                cnt += 1
        return dels
