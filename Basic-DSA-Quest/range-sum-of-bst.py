# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        def solve(root, low, high):
            nonlocal res
            if root.val >= low and root.val <= high:
                res += root.val
            if root.left:
                solve(root.left, low, high)
            if root.right:
                solve(root.right, low, high)
                
        res = 0
        if root:
            solve(root, low, high)
        return res
