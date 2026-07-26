class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        # Our memory pad: it stores answers for (eggs_left, floors_left)
        memo = {}
        
        def solve(eggs, floors):
            # 1. Base Cases
            if eggs == 1: return floors
            if floors == 0 or floors == 1: return floors
            
            # 2. Memo Check: Have we solved this exact scenario before?
            if (eggs, floors) in memo:
                return memo[(eggs, floors)]
            
            ans = float('inf')
            
            # 3. Binary Search (Instead of a for loop)
            low, high = 1, floors
            
            while low <= high:
                mid = (low + high) // 2  # Try dropping from the middle floor
                
                broke = solve(eggs - 1, mid - 1)      # Pain of breaking
                not_broke = solve(eggs, floors - mid) # Pain of surviving
                
                # Calculate the worst possible outcome for this drop
                worst_case = 1 + max(broke, not_broke)
                
                # Record this if it's the best strategy we've found so far
                ans = min(ans, worst_case)
                
                # 4. Adjust the Binary Search window to find the sweet spot
                if broke > not_broke:
                    # Breaking hurts more. We dropped from too high up.
                    # Shift our search downward.
                    high = mid - 1
                else:
                    # Surviving hurts more. We dropped from too low.
                    # Shift our search upward.
                    low = mid + 1
                    
            # 5. Save the final answer to our memo before returning
            memo[(eggs, floors)] = ans
            return ans
            
        return solve(k, n)