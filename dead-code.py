from typing import List

class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        n = len(positions)
        indices = list(range(n))
        result = []
        stack = []
        
        # Sort indices based on positions
        indices.sort(key=lambda i: positions[i])
        
        # Process each robot
        for current_index in indices:
            if directions[current_index] == 'R':
                # Push the current robot's index onto the stack
                stack.append(current_index)
            else:  # current robot is moving left ('L')
                while stack and healths[current_index] > 0:
                    right_index = stack.pop()
                    if healths[right_index] > healths[current_index]:
                        # Right-moving robot wins
                        healths[right_index] -= 1
                        # Push the right-moving robot back onto the stack
                        stack.append(right_index)
                        healths[current_index] = 0
                    elif healths[right_index] < healths[current_index]:
                        # Left-moving robot wins
                        healths[current_index] -= 1
                        healths[right_index] = 0
                    else:
                        # Both robots are equal
                        healths[right_index] = 0
                        healths[current_index] = 0

        # Collect surviving robots
        for i in range(n):
            if healths[i] > 0:
                result.append(healths[i])

        return result
