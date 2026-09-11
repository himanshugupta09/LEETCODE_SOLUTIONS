class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        hashed = set()
        n = len(digits)
        
        def solve(strng,vis):
            if len(strng) == 3:
                if strng[0] != '0' and int(strng)%2 == 0:
                    hashed.add(strng)
                return

            for i in range(0,n):
                if vis[i]:
                    continue
                vis[i] = True
                solve(strng + str(digits[i]), vis)
                vis[i] = False
        solve('',[False]*n)
        #print(hashed)
        return len(hashed)

        