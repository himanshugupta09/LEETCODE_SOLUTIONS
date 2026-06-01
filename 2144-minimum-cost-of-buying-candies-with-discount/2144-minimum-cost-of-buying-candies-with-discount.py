class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        if len(cost) <= 2:
            return sum(cost)
        total = 0
        cost.sort(reverse = True)
        for i in range(len(cost)):
            if i%3 != 2:
                total += cost[i]
        return total


        
        