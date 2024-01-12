class Solution:
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        res = []
        
        for i in range(len(favoriteCompanies)):
            now  = set(favoriteCompanies[i])
            #print(now)
            ct = 0
            for j in range(0,len(favoriteCompanies)):
                if i == j:
                    continue
                else:
                    t = set(favoriteCompanies[j])
                    if len(now.intersection(t))  >= len(now):
                        ct += 1
                        #print(now.intersection(t))
            if ct == 0:
                res.append(i)
        return res
        
