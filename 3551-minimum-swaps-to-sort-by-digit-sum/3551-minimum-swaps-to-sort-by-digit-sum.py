class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        def digitSum(num):
            sum = 0
            while num != 0:
                sum += (num%10)
                num //= 10
            return sum
        
        mapper = {nums[i]:i for i in range(n)}
        comp = [[nums[i],digitSum(nums[i]),i] for i in range(n)]
        comp.sort(key=lambda x: (x[1], x[0]))
        p = [0]*n
        for i in range(n):
            p[mapper[comp[i][0]]] = i
        vis = [False]*n
        swaps = 0
        for i in range(n):
            if vis[i] or p[i] == i:
                continue
            cycle = 0
            j = i
            while not vis[j]:
                vis[j] = True
                cycle += 1
                j = p[j]
            swaps += cycle-1
        return swaps
         


        