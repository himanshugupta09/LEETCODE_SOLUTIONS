class Solution:
    MOD = 10**9 + 7

    def numOfWays(self, nums: list[int]) -> int:
        n = len(nums)

        fact = [1] * (n + 1)
        invfact = [1] * (n + 1)

        def modPow(a, b):
            res = 1
            while b:
                if b & 1:
                    res = res * a % self.MOD
                a = a * a % self.MOD
                b >>= 1
            return res

        def nCr(n, r):
            return (
                fact[n] * invfact[r] % self.MOD
                * invfact[n - r] % self.MOD
            )

        # Precompute factorials
        for i in range(1, n + 1):
            fact[i] = fact[i - 1] * i % self.MOD

        # Precompute inverse factorials
        invfact[n] = modPow(fact[n], self.MOD - 2)

        for i in range(n, 0, -1):
            invfact[i - 1] = invfact[i] * i % self.MOD

        def solve(arr):
            size = len(arr)

            if size <= 1:
                return (size, 1)

            root = arr[0]
            left = []
            right = []

            for x in arr[1:]:
                if x < root:
                    left.append(x)
                else:
                    right.append(x)

            L, left_ways = solve(left)
            R, right_ways = solve(right)

            ways = nCr(L + R, L)
            ways = ways * left_ways % self.MOD
            ways = ways * right_ways % self.MOD

            return (size, ways)

        _, total_ways = solve(nums)

        # Exclude the original insertion order
        return (total_ways - 1 + self.MOD) % self.MOD