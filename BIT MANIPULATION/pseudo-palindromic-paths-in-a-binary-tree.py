# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        res = 0
        def solve(root,val):
            nonlocal res
            if not root:
                return
            val ^= 1 << root.val
            
            if (not(root.left) and not(root.right)):
                if val == 0 or (val&(val-1) == 0):
                    res += 1
                return
            solve(root.left,val)
            solve(root.right,val)
        
        solve(root,0)
        return  res
            
        
