from typing import Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        tree_map = {}
        
        def traverse(root):
            if root is None:
                return 0

            if root.val not in tree_map:
                tree_map[root.val] = []
                

            if root.left:
                tree_map[root.left.val] = []
                tree_map[root.left.val].append(root.val)
                tree_map[root.val].append(root.left.val)

            if root.right:
                tree_map[root.right.val] = []
                tree_map[root.right.val].append(root.val)
                tree_map[root.val].append(root.right.val)

            return 1 + traverse(root.left) + traverse(root.right)
        traverse(root)
        #res = 0
        #print(tree_map)
        
        if len(tree_map) == 1:
            return 0
        
        distance = [-1] * (max(tree_map.keys()) + 1)

        queue = deque([start])
        distance[start] = 0

        while queue:
            current_node = queue.popleft()

            for neighbor in tree_map[current_node]:
                if distance[neighbor] == -1:
                    distance[neighbor] = distance[current_node] + 1
                    queue.append(neighbor)

        
        return max(distance)
        
            
        
