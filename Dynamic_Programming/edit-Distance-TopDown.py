class Solution:
    def solve(self, s1, s2, i, j, memo):
        if i < 0:
            return j + 1
        if j < 0:          # <-- Add this base case
            return i + 1

        if (i, j) in memo:
            return memo[(i, j)]

        if s1[i] == s2[j]:
            ans = self.solve(s1, s2, i - 1, j - 1, memo)
        else:
            ans = 1 + min(
                self.solve(s1, s2, i - 1, j, memo),      # delete
                self.solve(s1, s2, i - 1, j - 1, memo),  # replace
                self.solve(s1, s2, i, j - 1, memo)       # insert
            )

        memo[(i, j)] = ans
        return ans

    def editDistance(self, s1, s2):
        i = len(s1) - 1
        j = len(s2) - 1
        memo = {}
        return self.solve(s1, s2, i, j, memo)